#include"../include/menu.hpp"

int Menu::type() {

    return int(PanelType::MENU);
}

int Menu::body() {

    PanelType ret = PanelType::MENU;
    while(ret != PanelType::EXIT) {
        //run menu screen
            //based on user choice, launch anoter Panel
    }
}

Menu::Menu(): Panel(), panels() {

    panels[PanelType::OPTIONS] = Options();
    panels[PanelType::LEVEL]   = Level();
    panels[PanelType::WIN]     = WinScreen();
    panels[PanelType::LOSS]    = LossScreen();
}