#include"../include/menu.h"

Menu::Menu(Graphics& g): GameComponent(), g(g) {

    cout << "Menu::Menu() " << this << endl;
}

Menu::~Menu() {

    cout << "Menu::~Menu() " << this << endl;
}

map_type Menu::type() { return 'm'; }

map_type Menu::get_type() { return Menu::type(); }

map_type Menu::exec() {
    
    return Level::type();
}
