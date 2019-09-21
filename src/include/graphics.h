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
    bool needs_freeing;
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
        //fattori di scala (usati per ridimensionare il buffer)
        float scale[4];

        int row;
        //per ogni GameComponent, contiene le immagini che compongono backgrounds e simili
        vector<vector<ALLEGRO_BITMAP*> > bitmaps;
        //coda di immagini da disegnare sul buffer
        vector<Image> queue;

        //restituisce i parametri adatti per l'inizializzazione del display
        ALLEGRO_DISPLAY_MODE getDispMode();
        //calcola i fattori di scala per questo particolare display
        void calc_scale_factors();

    protected:
    
    public:
        //funzione che si occupa di inizializzare le componenti grafiche
        Graphics();
        //?? costruttore con parametri (magari per l'inizializzazione del display) ??//
        //Graphics(...)
        //dealloca le risorse di Allegro
        ~Graphics();

        //imposta quale GameComponent sta venendo disegnata
        void set_component(int index) { row = index; } 
        //aggiunge una bitmap alla queue prendendola da backgrounds
        void push_image(int, float, float);
        void push_permanent_image(int, float, float);
        void push_shifted_image(int, float, float, float);
        //disegna gli elementi presenti nella queue, consumandoli se is_permanent = false
        void redraw();
        //elimina tutti gli elementi nella queue e resetta il buffer
        void clear() { queue.clear(); }

        float get_buffer_height() const { return buffer.y; }
        float get_buffer_width() const { return buffer.x; }
};

#endif