#include"../include/gamemanager.h"
#include<allegro5/allegro.h>

int main(int argv, char** argc) {

    Graphics g;
    GameManager gm(g);
//    al_rest(1.0);
    Level l(g);
//    al_rest(1.0);
    gm.add(&l);
    
    return 0;
}