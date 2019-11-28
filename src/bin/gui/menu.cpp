#include"../../include/gui/menu.hpp"

PanelType Menu::runMenuScreen() {

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
                    ret = directions[focus];
                    exit = true;
                } 

            break;

            case Event::Redraw:
                for(unsigned i = 0; i < button_released.size(); ++i)
                 if(i != focus) {
                    Graphics::getInstance().schedule_drawing(button_released[i]);
                    Graphics::getInstance().schedule_text(
                        button_text[i].data(), button_released[i]->get_x()+50, button_released[i]->get_y()+50, al_map_rgb(255, 255, 255));
                }
                Graphics::getInstance().schedule_drawing(button_pressed[focus]);
                Graphics::getInstance().schedule_text(
                    button_text[focus].data(), button_released[focus]->get_x()+50, button_released[focus]->get_y()+50, al_map_rgb(255, 255, 255));
                
                Graphics::getInstance().redraw();

            break;

            default:
            break;
        }
    }

    EventHandler::getInstance().suspend();

    return ret;
}

PanelType Menu::type() {

    return PanelType::MENU;
}

PanelType Menu::body(PanelType caller) {

    PanelType executor = PanelType::MENU;
    PanelType swap = caller;
    
    while(executor != PanelType::EXIT) {
    
        if(executor == PanelType::MENU)
            caller = runMenuScreen();
        else
            caller = panels.at(executor)->execute(caller);

        swap = executor;
        executor = caller;
        caller = swap;
    }

    return executor;
}

Menu::Menu(): Panel(), panels(), button_pressed(), button_released(), directions() {

    std::cout << "\nMenu initialization... ";
    
    Graphics::getInstance().set_component(this->type());
    EventHandler::getInstance();

    auto& context = Graphics::getInstance().get_initializer();

    directions = {PanelType::LEVEL, PanelType::OPTIONS, PanelType::EXIT};
    button_text ={"Level", "Options", "Exit"};
    for(int i = 0; i < 3; ++i) {
        button_pressed.push_back( new Image(context[0], 200, 100 + 120*i, false));
        button_released.push_back(new Image(context[1], 200, 100 + 120*i, false));
    }

    panels[PanelType::OPTIONS] = new Options();
    panels[PanelType::LEVEL]   = new Level();
    panels[PanelType::WIN]     = new WinScreen();
    panels[PanelType::LOSS]    = new LossScreen();

    std::cout << "Menu initalization done.\n";
}

Menu::~Menu() {

    for(auto it : panels)
        delete it.second;
    for(auto it : button_pressed)
        delete it;
    for(auto it : button_released)
        delete it;
}

void Menu::launchGame() {

    std::cout << "\nMenu::launchGame() called... ";

    this->execute(PanelType::MENU);
    EventHandler::delInstance();
    Graphics::delInstance();
    
    std::cout << "Menu::launchGame() done.\n";
}