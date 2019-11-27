#include"../../include/gui/menu.hpp"

PanelType Menu::runMenuScreen() {

    return PanelType::LEVEL;
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

Menu::Menu(): Panel(), panels() {

    std::cout << "\nMenu initialization... ";
    
    Graphics::getInstance()->set_component(this->type());
    EventHandler::getInstance();

    panels[PanelType::OPTIONS] = new Options();
    panels[PanelType::LEVEL]   = new Level();
    panels[PanelType::WIN]     = new WinScreen();
    panels[PanelType::LOSS]    = new LossScreen();

    std::cout << "Menu initalization done.\n";
}

Menu::~Menu() {

    for(auto it : panels)
        delete it.second;
}

void Menu::launchGame() {

    std::cout << "\nMenu::launchGame() called... ";

    this->execute(PanelType::MENU);
    EventHandler::delInstance();
    Graphics::delInstance();

    std::cout << "Menu::launchGame() done.\n";
}