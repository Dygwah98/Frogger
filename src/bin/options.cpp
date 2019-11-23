#include"../include/options.hpp"

PanelType Options::type() {

    return PanelType::OPTIONS;
}

PanelType Options::body(PanelType caller) {
    
    Graphics::getInstance()->set_component(this->type());
    
    return PanelType::EXIT;
}

Options::Options(): Panel() {}