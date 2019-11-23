#include"../include/options.hpp"

PanelType Options::type() {

    return PanelType::OPTIONS;
}

PanelType Options::body(PanelType caller) {
    
}

Options::Options(): Panel() {}