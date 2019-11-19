#include"../include/level.hpp"

void Level::update_game_state() {

}

Panel::PanelType Level::type() {

    return PanelType::LEVEL;
}

Panel::PanelType Level::body(PanelType caller) {

    //imposta la row da cui prendere le bitmaps
    Graphics* g      = Graphics::getInstance();
    EventHandler* eh = EventHandler::getInstance();
    
    g->set_component(int(this->type()));
    eh->launch();

    while(!exit) {

        Event e = EventHandler::getInstance()->next_event();
        switch(e) {
            
            case Event::Exit:   exit = true;    break;
            case Event::Pause:  pause = !pause; break;

            case Event::Execute:

                if(!pause) {
                    
                    //eventuali singole modifiche vanno fatte qui
                    update_game_state();
                }

                break;

            case Event::Redraw:

                if(!pause) {
                    
                    //qua vanno le chiamate di disegno del livello
                    g->redraw();
                }

                break;

            default:

                std::cout << "UNHANDLED EVENT\n";
            
                break;
        }
    }

    eh->suspend();

    return PanelType::EXIT;
}

Level::Level(): Panel() {}