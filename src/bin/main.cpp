#include"../include/gamemanager.h"
#include<allegro5/allegro.h>

int main(int argv, char** argc) {

    cout << endl << "STARTING: " << argc[0] << endl << endl;

    //allocazioni delle risorse
    Graphics g;
    GameManager gm(g);
    
    GameComponent* l = new Level(g);
    gm.add(l);

    GameComponent* m = new Menu(g);
    gm.add(m);

    //deallocazioni dinamiche delle risorse
    cout << endl;
    delete m;
    delete l;

    //deallocazioni statiche delle risorse
    cout << endl;
    return 0;
}