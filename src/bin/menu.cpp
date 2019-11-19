#include"../include/menu.hpp"

Panel::PanelType Menu::runMenuScreen() {

    return PanelType::LEVEL;
}

Panel::PanelType Menu::type() {

    return PanelType::MENU;
}

Panel::PanelType Menu::body(PanelType ret) {

    Panel* next;
    while(ret != PanelType::EXIT) {
        
        ret  = runMenuScreen();
        next = panels.at(ret);
        ret  = next->execute(Menu::type());
    }

    return ret;
}

Menu::Menu(): Panel(), panels() {

    panels[PanelType::OPTIONS] = new Options();
    panels[PanelType::LEVEL]   = new Level();
    panels[PanelType::WIN]     = new WinScreen();
    panels[PanelType::LOSS]    = new LossScreen();
}

Menu::~Menu() {

    for(auto& it : panels)
        delete it.second;
}

void Menu::launchGame() {

    this->execute(PanelType::MENU);
    Graphics::delInstance();
    EventHandler::delInstance();
}