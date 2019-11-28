#include"../../include/gui/winlose.hpp"

PanelType WinScreen::type() {

    return PanelType::WIN;
}

PanelType WinScreen::body(PanelType caller) {

    EventHandler::getInstance().launch();

    Event ev;
    Keys k = Keys::nd;
    bool exit = false;
    while(!exit) {
        ev = EventHandler::getInstance().next_event();
        switch(ev) {

            case Event::Execute:
                k = EventHandler::getInstance().next_key();
                if(k != Keys::nd)
                    exit = true;
            break;

            case Event::Redraw:
                Graphics::getInstance().schedule_drawing(background);
                Graphics::getInstance().redraw();
            break;

            default:
            break;
        }
    }

    EventHandler::getInstance().suspend();

    return PanelType::MENU;
}

WinScreen::WinScreen(): Panel() {

    std::cout << "\nWinScreen initialization\n";

    Graphics::getInstance().set_component(this->type());
    EventHandler::getInstance();

    auto& context = Graphics::getInstance().get_initializer();

    background = new Image(context[0], 0.0f, 0.0f, false);
}

WinScreen::~WinScreen() {

    delete background;
}

//LossScreen methods

PanelType LossScreen::type() {

    return PanelType::LOSS;
}

PanelType LossScreen::body(PanelType caller) {

    EventHandler::getInstance().launch();

    Event ev;
    Keys k = Keys::nd;
    bool exit = false;
    while(!exit) {
        ev = EventHandler::getInstance().next_event();
        switch(ev) {

            case Event::Execute:
                k = EventHandler::getInstance().next_key();
                if(k != Keys::nd)
                    exit = true;
            break;

            case Event::Redraw:
                Graphics::getInstance().schedule_drawing(background);
                Graphics::getInstance().redraw();
            break;

            default:
            break;
        }
    }

    EventHandler::getInstance().suspend();

    return PanelType::MENU;
}

LossScreen::LossScreen(): Panel() {
   
    std::cout << "\nLossScreen initialization\n";

    Graphics::getInstance().set_component(this->type());
    EventHandler::getInstance();

    auto& context = Graphics::getInstance().get_initializer();

    background = new Image(context[0], 0.0f, 0.0f, false);
}


LossScreen::~LossScreen() {

    delete background;
}