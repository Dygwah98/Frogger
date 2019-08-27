#include"../include/menu.h"

Menu::Menu(Graphics& g): GameComponent(), g(g) {

    cout << "Menu::Menu() " << this << endl;
}

Menu::~Menu() {

    cout << "Menu::~Menu() " << this << endl;
}