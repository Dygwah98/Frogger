#include"../include/gamemanager.h"
#include<allegro5/allegro.h>

int main(int argv, char** argc) {

    //allocazioni delle risorse    
    cout << endl << "ALLOCAZIONE: " << argc[0] << endl << endl;

    Graphics g;
    GameManager gm(g);
    
    GameComponent* l = new Level(g);
    gm.add(l);

    GameComponent* m = new Menu(g);
    gm.addAsRoot(m);

    //avvio del gioco       
    cout << endl << "ESECUZIONE: " << argc[0] << endl << endl;

    gm.launchGame();

    //deallocazioni dinamiche delle risorse   
    cout << endl << "DEALLOCAZIONE: " << argc[0] << endl << endl;
    
    delete m;
    delete l;

    //deallocazioni statiche delle risorse
    cout << endl;
    return 0;
}