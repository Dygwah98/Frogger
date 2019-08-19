#include"root.h"
/*
    si occupa di disegnare le varie linee e il player on top of that
    - dovrebbe gestire anche le animazioni?
        - se si, deve anche comunicare lo stop ai controlli?
*/
class Graphics {

    private:
        //true se l'inizializzazione di Allegro va a buon fine
        static bool isValid;
        //funzione che inizializza le componenti interne di Allegro
        static bool initAllegro();
        //restituisce i parametri adatti per l'inizializzazione del display
        ALLEGRO_DISPLAY_MODE getDispMode();

        ALLEGRO_DISPLAY* display;
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT_QUEUE* event_queue;

    protected:
    
    public:
        //funzione che si occupa di inizializzare le componenti grafiche
        Graphics();
        //?? costruttore con parametri (magari per l'inizializzazione del display) ??//
        //Graphics(...)
        //dealloca le risorse di Allegro
        ~Graphics();
        //true se tutte le componenti sono valide per l'uso
        bool is_ready() const;
        //avvia il timer e la coda degli eventi
        void launch();
        //stoppa il timer e la coda degli eventi
        void suspend();
};