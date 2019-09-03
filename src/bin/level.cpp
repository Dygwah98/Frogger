#include"../include/level.h"

Level::Level(EventHandler& eh): GameComponent(), graphics(eh.get_graphic_context()), events(eh), lines(), player() {

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}

GameComponent::map_type Level::type() { return GameComponent::types[2]; }

GameComponent::map_type Level::get_type() { return Level::type(); }

GameComponent::map_type Level::exec() {

    map_type ret = GameComponent::exit_val();

    bool STOP = false;

    events.launch();
    //alcune shortcut per rendere più leggibile il codice
    const auto& is_player_on_a_line = [&]() -> bool { return lines.find(player.get_position()) != lines.end(); };
    const auto& player_does_collide = [&]() -> bool { return lines.at(player.get_position()).check_for_collision(player); };

    while(!STOP) {

        const Event& ev = events.next_event();
        switch(ev) {
            case Event::Exit:        
                STOP = true;
            break;

            case Event::Execute:
                //controlla se sono avvenute collisioni sulla linea sulla quale si trova il player
                if(is_player_on_a_line() and player_does_collide()) {
                    
                    player.lose_life();
                    //se il player arriva a 0 vite: 
                    if(player.is_dead()) {
                        STOP = true;
                        break;
                    } else {
                        //i valori esatti vanno ancora determinati
                        player.reposition(0, 0.0f);
                    }
                }
                //controlla se il player deve muoversi
                if(!player.is_moving() and events.next_key() != Keys::nd) {
                    
                    //se si: attiva il movimento
                
                } else if(player.is_moving()) {
                
                    //se si: continua il movimento
                
                }
                //shifta ogni linea secondo la sua velocità
                for(auto& it : lines)
                    it.second.shift_head();
            
            break;

            case Event::Redraw:
                //call the graphic routines
                //graphics.push_image per ogni componente da rappresentare
                graphics.redraw();

            break;
            
            default:
            break;
        }
    }
    
    events.suspend();
    
    return ret;
}