#include"../include/winlose.hpp"

Panel::PanelType WinScreen::type() {

    return PanelType::WIN;
}

Panel::PanelType WinScreen::body(PanelType caller) {

}

WinScreen::WinScreen(): Panel() {}

//LossScreen methods

Panel::PanelType LossScreen::type() {

    return PanelType::LOSS;
}

Panel::PanelType LossScreen::body(PanelType caller) {
    
}

LossScreen::LossScreen(): Panel() {}