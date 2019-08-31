#ifndef ROOT_H
#define ROOT_H

#include<iostream>
#include<cassert>
#include<vector>
#include<map>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
using namespace std;

template<class T>
inline bool in_range(T lower, T val, T upper, bool loweq = true, bool upeq = true) {
    return (loweq ? val >= lower : val > lower) and (upeq ? upper >= val : upper > val);
}

#endif

//LOGICA
/*
    oggetto rappresentante un'entita' (monostato) sulla linea
    - può essere specializzata per entita' multistato (nemici con animazioni/altro)
*/
//class GameObject;
/*
    rappresenta una riga dell'area di gioco
    - si limita a contenere una rappresentazione minimale dei vari oggetti
        - identificativo per il tipo + lungezza dell'oggetto   
            - si potrebbero usare anche oggetti a dimensione fissa
    - può verificare se in una data posizione si verifica una collisione

    interfaccia leggera e semplice per Level, così da nascondere la complessità interna
*/
//class Line;
/*
    istanza del giocatore, solite cose
*/
//class Player;
/*
    rappresenta l'intera istanza (solo logica?) di un livello

    vab, quantomeno l'handle alla grafica? O viceversa
*/
//class Level;

//END LOGICA
//GRAFICA

/*
    gestisce l'animazione come sequenza di bitmaps connesse fra loro
*/
//class Animation;
/*
    si occupa di disegnare le varie linee e il player on top of that
    - dovrebbe gestire anche le animazioni?
        - se si, deve anche comunicare lo stop ai controlli?
*/
//class Graphics;

//END GRAFICA