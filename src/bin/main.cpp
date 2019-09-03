#include"../include/gamemanager.h"
#include<allegro5/allegro.h>

int main(int argv, char** argc) {

    //allocazioni delle risorse    
    cout << endl << "ALLOCAZIONE: " << argc[0] << endl << endl;

    Graphics g;
    EventHandler ev(g);
    GameManager gm(ev);

    GameComponent* m = new Menu(ev);
    gm.addAsRoot(m);
    
    GameComponent* l = new Level(ev);
    gm.add(l);

    //avvio del gioco       
    cout << endl << "ESECUZIONE: " << argc[0] << endl << endl;

    gm.launchGame();

    //deallocazioni dinamiche delle risorse   
    cout << endl << "DEALLOCAZIONE: " << argc[0] << endl << endl;
    
    delete l;
    delete m;

    //deallocazioni statiche delle risorse
    cout << endl;
    return 0;
}