#include"../include/level.hpp"

void Level::update_game_state() {

    switch(player_collides()) {

        case Collision::Deadly:
            player.lose_life(); 
            if(player.is_dead()) exit = true;
            else                 player.reposition(0, 0.0f);            
            break;
        
        case Collision::Arrival:
            ++frogs_counter;
            if(frogs_counter >= 5)
                exit = true;
            break;
        
        case Collision::Log:
            player.reposition(player.get_position(), player.get_coord() + player_line().get_speed());
            break;

        default:
            std::cout << "UNHANDLED COLLISION\n";
            break;
    }

    if(!player.is_dead) {
        if(!player.is_moving()) {
        
            Keys temp = EventHandler::getInstance()->next_key();

            if(temp != Keys::nd)
                player.set_dir(temp);
        
            if(player_in_area()) player.move();
            else                 player.set_still();   
        
        } else 
            player.move();
    }
    
    //update lines
}

void Level::reset_game_state() {

    exit = false;
    pause = false;
    frogs_counter = 0;
    player.reset();
    //reset lines
}

void Level::redraw_game() {

    //redraw delle lines
    player.redraw();
    Graphics::getInstance()->redraw();
}

PanelType Level::type() {

    return PanelType::LEVEL;
}

PanelType Level::body(PanelType caller) {

    reset_game_state();

    Graphics::getInstance()->set_component(this->type());
    EventHandler::getInstance()->launch();

    while(!exit) {

        Event e = EventHandler::getInstance()->next_event();
        switch(e) {
            
            case Event::Exit:          
                exit = true;    
                break;
            
            case Event::Pause:  
                pause = !pause; 
                break;

            case Event::Execute: 
                if(!pause) update_game_state();
                break;

            case Event::Redraw:
                if(!pause) redraw_game();
                break;

            default:
                std::cout << "UNHANDLED EVENT\n";
                break;
        }
    }

    EventHandler::getInstance()->suspend();

    return PanelType::EXIT;
}

Level::Level(): 
    Panel(), exit(false), pause(false), player(), frogs_counter(0) {}