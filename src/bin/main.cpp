#include"../include/gamemanager.h"
#include<allegro5/allegro.h>

int main(int argv, char** argc) {

    Graphics g;
    GameManager gm(g);
    
    Level l(g);
    gm.add(&l);

    Menu m(g);
    gm.add(&m);

    return 0;
}