#include"../include/menu.h"

Menu::Menu(EventHandler& eh): GameComponent(), graphics(eh.get_graphic_context()), events(eh) {

    cout << "Menu::Menu() " << this << endl;
}

Menu::~Menu() {

    cout << "Menu::~Menu() " << this << endl;
}

GameComponent::map_type Menu::type() { return GameComponent::types[1]; }

GameComponent::map_type Menu::get_type() { return Menu::type(); }

GameComponent::map_type Menu::exec() {
    
    return Level::type();
}
