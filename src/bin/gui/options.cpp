#include"../../include/gui/options.hpp"

PanelType Options::type() {

    return PanelType::OPTIONS;
}

PanelType Options::body(PanelType caller) {
    
        EventHandler::getInstance().launch();

    PanelType ret = PanelType::EXIT;

    Event ev;
    int focus = 0;
    bool exit = false;
    Keys t = Keys::nd;
    while(!exit) {
        
        ev = EventHandler::getInstance().next_event();
        switch(ev) {
            
            case Event::Exit:
                exit = true;
            break;

            case Event::Execute:
                
                t = EventHandler::getInstance().next_key();
                if(t == Keys::UP) {
                    focus -= 1;
                    focus %= button_released.size();

                } else if(t == Keys::DOWN) {
                    focus += 1;
                    focus %= button_released.size();
                } else if(t == Keys::ENTER) {
                    if(focus != 0) {
                        ret = directions[focus];
                        exit = true;
                    } else {
                        switch(d) {
                            case Level::Difficulty::EASY:   d = Level::Difficulty::NORMAL; break;
                            case Level::Difficulty::NORMAL: d = Level::Difficulty::HARD;   break;
                            case Level::Difficulty::HARD:   d = Level::Difficulty::EASY;   break;
                        }
                        l.set_difficulty_to(d);
                    }
                }

            break;

            case Event::Redraw:
                for(unsigned i = 0; i < button_released.size(); ++i)
                 if(i != focus) {
                    Graphics::getInstance().schedule_drawing(button_released[i]);
                    Graphics::getInstance().schedule_text(
                        button_text[i].data(), 
                        button_released[i]->get_x()+25, 
                        button_released[i]->get_y()+25, 
                        al_map_rgb(255, 255, 255)
                    );
                }
                Graphics::getInstance().schedule_drawing(button_pressed[focus]);
                Graphics::getInstance().schedule_text(
                    button_text[focus].data(), 
                    button_released[focus]->get_x()+25, 
                    button_released[focus]->get_y()+25, 
                    al_map_rgb(255, 255, 255)
                );

                switch(d) {
                    case Level::Difficulty::EASY:   
                        Graphics::getInstance().schedule_text(
                            "EASY", button_released[0]->get_x()+225, button_released[0]->get_y()+25, al_map_rgb(255, 255, 255));
                    break;
                    case Level::Difficulty::NORMAL:
                        Graphics::getInstance().schedule_text(
                            "NORMAL", button_released[0]->get_x()+225, button_released[0]->get_y()+25, al_map_rgb(255, 255, 255));
                    break;
                    case Level::Difficulty::HARD:
                        Graphics::getInstance().schedule_text(
                            "HARD", button_released[0]->get_x()+225, button_released[0]->get_y()+25, al_map_rgb(255, 255, 255));
                    break;
                }
                        
                
                Graphics::getInstance().redraw();

            break;

            default:
            break;
        }
    }

    EventHandler::getInstance().suspend();

    return ret;
}

Options::Options(Level& lev): Panel(), l(lev), d(Level::Difficulty::NORMAL) {

    std::cout << "\nOptions initialization... ";

    Graphics::getInstance().set_component(this->type());
    EventHandler::getInstance();

    auto& context = Graphics::getInstance().get_initializer();

    directions  = {PanelType::OPTIONS, PanelType::MENU, PanelType::EXIT};
    button_text = {"Difficulty: ",     "Menu",          "Exit"         };
    
    for(int i = 0; i < 3; ++i) {

        button_pressed.push_back( new Image(context[0], 200, 100 + 120*i, false));
        button_released.push_back(new Image(context[1], 200, 100 + 120*i, false));
    }

    std::cout << "Options initialization done.\n";
}