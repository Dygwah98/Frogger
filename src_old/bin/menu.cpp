#include"../include/menu.h"

Menu::Menu(EventHandler& eh): GameComponent(ret_val()), graphics(eh.get_graphic_context()), events(eh) {

    cout << "Menu::Menu() " << this << endl;
}

Menu::~Menu() {

    cout << "Menu::~Menu() " << this << endl;
}

int Menu::exec() {
    
    cout << "Menu::exec() " << this << endl;

    return Level::get_type();
}
