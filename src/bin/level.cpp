#include"../include/level.h"

Level::Level(EventHandler& eh): 
    GameComponent(), graphics(eh.get_graphic_context()), events(eh), lines(), 
    player(eh.get_graphic_context(), 1, 0, 0.0f), is_stopped(false), frogs_counter(0) {

    Line::setLineDimension(520.0f);

    for(unsigned i = 0; i < 11; ++i) lines.push_back({});

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}

Collision Level::player_collides() const { 

    Collision ret = GameObject::null_val();
    
    if(contains<Line>(lines, player.get_position()))
        ret = player_line().check_for_collision(player);

    return ret;
}

bool Level::handle_collisions() {

    //controlla se sono avvenute collisioni sulla linea sulla quale si trova il player
    switch(player_collides()) {

        //se la collisione è letale
        case Collision::Deadly:
            //il player perde una vita
            player.lose_life();
            //se il player arriva a 0 vite: 
            if(player.is_dead()) 
                return true;
            //altrimenti: viene riposizionato all'inizio del livello
            else 
                //i valori esatti vanno ancora determinati
                player.reposition(0, 0.0f);
                        
        break;
        
        //se il player ha raggiunto il punto d'arrivo
        case Collision::Arrival:
            //il player viene riposizionato, e all'interno di level va registrata la nuova situazione
            ++frogs_counter;
            if(frogs_counter >= 5)
                return true;
        break;
        
        //se il player si trova su una piattaforma mobile
        case Collision::Log:
            //il player viene riposizionato a ogni iterazione, shiftandolo alla velocità della line 
            player.reposition(player.get_position(), player.get_coord() + player_line().get_speed());
        break;

        default:
        break;
    }

    return false;
}

void Level::update_player() {
    //controlla se il player deve muoversi
    //se è stato premuto un tasto: 
    if(!player.is_moving()) {
        
        if(events.next_key() != Keys::nd)
            //viene specificato al player che inizia il movimento
            player.set_dir(events.next_key());
        
        if(player_in_area()) 
            player.move();
        else                 
            player.set_still();   
    }
    else player.move();
}

void Level::update_lines() {

    //shifta ogni linea secondo la sua velocità
    for(Line& it : lines)
        it.shift_head();        
}

GameComponent::exec_type Level::exec() {

    GameComponent::exec_type ret = GameComponent::exit_val();

    cout << "Level::exec() " << this << endl;

    bool STOP = false;
    
    graphics.set_component(get_type());                
    graphics.push_permanent_image(0, 0.0f, 0.0f);

    events.launch();

    while(!STOP) {

        const Event& ev = events.next_event();
        switch(ev) {

            case Event::Execute:
                
                if(!is_stopped) {    
                    if(!player.is_dead()) {
                        STOP = handle_collisions();   
                        update_player();
                    } 
                    update_lines();
                }

            break;

            case Event::Redraw:
                //call the graphic routines
                if(!is_stopped) {
                    //graphics.push_image per ogni Line da rappresentare
                    for(int i = 0; i < 11; ++i)
                        graphics.push_shifted_image(2+i, 0, i * line_height(), lines[i].get_head());
                    //nella versione finale, da rimuovere
                    graphics.push_image(player.get_gindex(), player.get_coord() + 5.0f, player_gpos());
                    //esegue il redraw vero e proprio
                    graphics.redraw();
                }

            break;

            case Event::Exit:        
                //termina il loop di gioco e "chiude" il livello
                STOP = true;

            break;

            case Event::Stop:
                //mette in pausa il gioco
                is_stopped = !is_stopped;
            
            break;
            
            default:
            break;
        }
    }

/*blocco da rimuovere nella versione finale*/
    if(player.get_lifes() == 0)
        cout << "Sconfitta!\n";
    else if(frogs_counter >= 5)
        cout << "Vittoria!\n";
    else
        cout << "FORCED EXIT\n";
/*blocco da rimuovere nella versione finale*/

    events.suspend();

    return ret;
}