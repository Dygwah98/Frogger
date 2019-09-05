#include"../include/level.h"

Level::Level(EventHandler& eh): GameComponent(), graphics(eh.get_graphic_context()), events(eh), lines(), player() {

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}

bool Level::player_collides() const { 
        return 
            contains<int, Line>(lines, player.get_position()) and 
            lines.at(player.get_position()).check_for_collision(player);
};

GameComponent::map_type Level::type() { return GameComponent::types[2]; }

GameComponent::map_type Level::get_type() { return Level::type(); }

GameComponent::map_type Level::exec() {

    map_type ret = GameComponent::exit_val();

    bool STOP = false;

    events.launch();

    while(!STOP) {

        const Event& ev = events.next_event();
        switch(ev) {
            case Event::Exit:        
                STOP = true;
            break;

            case Event::Execute:
                //controlla se sono avvenute collisioni sulla linea sulla quale si trova il player
                if(player_collides()) {
                    //se avviene: il player perde una vita
                    player.lose_life();
                    //se il player arriva a 0 vite: 
                    if(player.is_dead()) {
                        STOP = true;
                        break;
                    //altrimenti: viene riposizionato all'inizio del livello
                    } else {
                        //i valori esatti vanno ancora determinati
                        player.reposition(0, 0.0f);
                    }
                }
                //controlla se il player deve muoversi
                //se è stato premuto un tasto: viene specificato al player che inizia il movimento
                if(!player.is_moving() and events.next_key() != Keys::nd) {
                    
                    player.set_dir(events.next_key());
                    player.move();
                //se si sta già movendo: continua (internamente gestirà il cambio del bool isMoving)
                } else if(player.is_moving()) {
                    
                    player.move();
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