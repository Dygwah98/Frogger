#include"../../include/gui/options.hpp"

PanelType Options::type() {

    return PanelType::OPTIONS;
}

PanelType Options::body(PanelType caller) {
    
    return PanelType::EXIT;
}

Options::Options(): Panel() {}