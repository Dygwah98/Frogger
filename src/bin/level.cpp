#include"../include/level.hpp"

void Level::update_game_state() {

    player.update_state();
    //update lines
}

void Level::reset_game_state() {

    //reset player
    //reset lines
}

void Level::redraw_game() {

    //redraw delle lines
    player.redraw();
    Graphics::getInstance()->redraw();
}

Panel::PanelType Level::type() {

    return PanelType::LEVEL;
}

Panel::PanelType Level::body(PanelType caller) {

    reset_game_state();

    //imposta la row da cui prendere le bitmap
    Graphics::getInstance()->set_component(int(this->type()));
    EventHandler::getInstance()->launch();

    while(!exit) {

        Event e = EventHandler::getInstance()->next_event();
        switch(e) {
            
            case Event::Exit:   exit = true;    break;
            case Event::Pause:  pause = !pause; break;

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

Level::Level(): Panel(), exit(false), pause(false) {}