#include"../include/menu.hpp"

Panel::PanelType Menu::type() {

    return PanelType::MENU;
}

Panel::PanelType Menu::body(PanelType ret) {

    while(ret != PanelType::EXIT) {
        //run menu screen
            //based on user choice, launch anoter Panel
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
}