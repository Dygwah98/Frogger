#include"../include/level.h"

Level::Level(EventHandler& eh): 
    GameComponent(), graphics(eh.get_graphic_context()), events(eh), lines(), player(), is_stopped(false) {

    Line::setLineDimension(graphics.get_buffer_width());

    for(unsigned i = 0; i < 11; ++i) lines[i] = Line();

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}

bool Level::player_collides() const { 
    
    return contains<int, Line>(lines, player.get_position()) and lines.at(player.get_position()).check_for_collision(player);
}

auto Level::special_condition() const {

    return false;
    //condizioni speciali che potrebbero influire sul giocatore: un getter per cosa si trova in player.pos?
    //return 
    //(contains<int, Line>(lines, player.get_position()))
    //? lines.at(player.get_position()).at(player.get_coord()).has_special_condition()
    //: qualcosa;
}

GameComponent::exec_type Level::exec() {

    GameComponent::exec_type ret = GameComponent::exit_val();

    bool STOP = false;

    events.launch();

    //nella versione finale, da rimuovere
    ALLEGRO_BITMAP* btemp = al_create_bitmap(30, 30);
    //nella versione finale, da rimuovere
    al_set_target_bitmap(btemp);
    //nella versione finale, da rimuovere
    al_clear_to_color(al_map_rgb(255, 255, 255));
    //nella versione finale, da rimuovere
    al_set_target_backbuffer(al_get_current_display());

    while(!STOP) {

        const Event& ev = events.next_event();
        switch(ev) {

            case Event::Execute:
                
                if(!is_stopped) {
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
                        if(player_in_area()) {
                            player.set_dir(events.next_key());
                            player.move();
                        }
                    //se si sta già movendo: continua (internamente gestirà il cambio del bool isMoving)
                    } else if(player.is_moving()) {
                    
                        player.move();
                    }
                    //shifta ogni linea secondo la sua velocità
                    for(auto& it : lines)
                        it.second.shift_head();
                    //gestisce le regole non previste nelle schema di base (isola le condizioni particolari)
                    switch(special_condition()) {
                        //applica la special condition (che sarebbe una qualunque regola di gioco)
                        default:
                        break;
                    }    
                }

            break;

            case Event::Redraw:
                //call the graphic routines
                if(!is_stopped) {
                    //graphics.push_image per ogni componente da rappresentare
                    //nella versione finale, da rimuovere
                    graphics.push_image(btemp, player.get_coord(), player.get_position(), Priority::FRONT, false);
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
    
    events.suspend();
    //nella versione finale, da rimuovere
    al_destroy_bitmap(btemp);

    return ret;
}