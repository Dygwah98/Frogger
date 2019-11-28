#include"../include/gui/menu.hpp"

int main(int argv, char** argc) {

    Menu* m = new Menu();
    m->launchGame();
    
    delete m;

    return 0;
}