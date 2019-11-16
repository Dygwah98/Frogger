#include"../include/level.hpp"

Panel::PanelType Level::type() {

    return PanelType::LEVEL;
}

Panel::PanelType Level::body(PanelType caller) {

}

Level::Level(): Panel() {}