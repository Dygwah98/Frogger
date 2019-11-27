#include"../../include/gui/options.hpp"

PanelType Options::type() {

    return PanelType::OPTIONS;
}

PanelType Options::body(PanelType caller) {
    
    return PanelType::EXIT;
}

Options::Options(): Panel() {

    std::cout << "\nOptions initialization... ";

    Graphics::getInstance()->set_component(this->type());
    EventHandler::getInstance();

    std::cout << "Options initialization done.\n";
}