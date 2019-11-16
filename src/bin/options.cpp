#include"../include/options.hpp"

Panel::PanelType Options::type() {

    return PanelType::OPTIONS;
}

Panel::PanelType Options::body(PanelType caller) {
    
}

Options::Options(): Panel() {}