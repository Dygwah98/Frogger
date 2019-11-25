#include"../../include/gui/winlose.hpp"

PanelType WinScreen::type() {

    return PanelType::WIN;
}

PanelType WinScreen::body(PanelType caller) {

    Graphics::getInstance()->set_component(this->type());
    
    return PanelType::EXIT;
}

WinScreen::WinScreen(): Panel() {}

//LossScreen methods

PanelType LossScreen::type() {

    return PanelType::LOSS;
}

PanelType LossScreen::body(PanelType caller) {
    
    Graphics::getInstance()->set_component(this->type());
    
    return PanelType::EXIT;
}

LossScreen::LossScreen(): Panel() {}