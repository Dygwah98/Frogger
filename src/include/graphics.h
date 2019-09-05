#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"root.h"
/*
    si occupa di disegnare le varie linee e il player on top of that
    - dovrebbe gestire anche le animazioni?
        - se si, deve anche comunicare lo stop ai controlli?
*/

struct Image {

    ALLEGRO_BITMAP* bitmap;
    float x;
    float y;
    bool is_permanent;

};

class EventHandler;
class Graphics {

    friend EventHandler;

    private:
        //true se l'inizializzazione di Allegro va a buon fine
        static bool isValid;
        //funzione che inizializza le componenti interne di Allegro
        static bool initAllegro();

        //struttura di Allegro per il disegno su schermo
        ALLEGRO_DISPLAY* display;
        //bitmap d'appoggio, usata per la scalabilità
        Image buffer;
        //fattore di scala
        int scaleW;
        //fattore di scala
        int scaleH;
        //fattore di scala
        int scaleX;    
        //fattore di scala
        int scaleY;
        //coda di immagini da disegnare sul buffer
        vector<Image> queue;

        //restituisce i parametri adatti per l'inizializzazione del display
        ALLEGRO_DISPLAY_MODE getDispMode();
        //getter del display
        ALLEGRO_DISPLAY* get_display();

    protected:
    
    public:
        //funzione che si occupa di inizializzare le componenti grafiche
        Graphics();
        //?? costruttore con parametri (magari per l'inizializzazione del display) ??//
        //Graphics(...)
        //dealloca le risorse di Allegro
        ~Graphics();
        //aggiunge una bitmap alla queue
        void push_image(ALLEGRO_BITMAP*, float, float, Priority, bool);
        //disegna gli elementi presenti nella queue, consumandoli se is_permanent = false
        void redraw();
        //elimina tutti gli elementi nella queue e resetta il buffer
        void clear();
};

#endif