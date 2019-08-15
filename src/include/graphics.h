#include"root.h"
/*
    si occupa di disegnare le varie linee e il player on top of that
    - dovrebbe gestire anche le animazioni?
        - se si, deve anche comunicare lo stop ai controlli?
*/
class Graphics {

    private:
        ALLEGRO_DISPLAY* display;

    protected:
    
    public:
        //funzione che si occupa di inizializzare i vari addon e le funzionalità di Allegro
        Graphics();
        //dealloca le risorse di Allegro
        ~Graphics();
};