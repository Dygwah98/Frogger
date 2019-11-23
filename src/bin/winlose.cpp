#include"../include/winlose.hpp"

PanelType WinScreen::type() {

    return PanelType::WIN;
}

PanelType WinScreen::body(PanelType caller) {

}

WinScreen::WinScreen(): Panel() {}

//LossScreen methods

PanelType LossScreen::type() {

    return PanelType::LOSS;
}

PanelType LossScreen::body(PanelType caller) {
    
}

LossScreen::LossScreen(): Panel() {}