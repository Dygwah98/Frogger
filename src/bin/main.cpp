#include"../include/gamemanager.h"
#include<allegro5/allegro.h>

int main(int argv, char** argc) {

    cout << endl;
    Graphics g;
    GameManager gm(g);
    
    GameComponent* l = new Level(g);
    gm.add(l);

    GameComponent* m = new Menu(g);
    gm.add(m);

    cout << endl << endl;
    delete m;
    delete l;
    return 0;
}