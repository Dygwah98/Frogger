#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include"image.hpp"
/*
    si occupa di disegnare le varie linee e il player on top of that
    - dovrebbe gestire anche le animazioni?
        - se si, deve anche comunicare lo stop ai controlli?
*/

class Graphics;
class Buffer : public ComplexImage {

    friend class Graphics;
    private:
        //fattori di scala (usati per ridimensionare il buffer)
        float scale[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    
    public:
        using ComplexImage::ComplexImage;
        
        void draw() override;
};

class EventHandler;
class Graphics {

    friend EventHandler;

    private:
        //true se l'inizializzazione di Allegro va a buon fine
        static bool isValid;
        //funzione che inizializza le componenti interne di Allegro
        static bool initAllegro();

        static Graphics* instance;
        //struttura di Allegro per il disegno su schermo
        ALLEGRO_DISPLAY* display;
        //bitmap d'appoggio, usata per la scalabilità
        Buffer buffer;

        PanelType row;
        //per ogni GameComponent, contiene le immagini che compongono backgrounds e simili
        std::map<PanelType, std::vector<ALLEGRO_BITMAP*> > bitmaps;
        //coda di immagini da disegnare sul buffer
        std::vector<Image*> queue;

        float line_dim;

        //restituisce i parametri adatti per l'inizializzazione del display
        ALLEGRO_DISPLAY_MODE getDispMode() const;
        //calcola i fattori di scala per questo particolare display
        void calc_scale_factors();

        Graphics();

    public:
        static Graphics* getInstance();

        static void delInstance();
        //dealloca le risorse di Allegro
        ~Graphics();

        //imposta quale GameComponent sta venendo disegnata
        void set_component(PanelType index);
        //aggiunge una bitmap alla queue prendendola da backgrounds
        void push_image(Image*);
        //disegna gli elementi presenti nella queue, consumandoli se is_permanent = false
        void redraw();
        //elimina tutti gli elementi nella queue e (al momento) NON resetta il buffer
        void clear() { queue.clear(); }

        float get_buffer_width() const { return buffer.get_x(); }
        float get_buffer_height() const { return buffer.get_y(); }
        unsigned get_refresh_rate() const { return getDispMode().refresh_rate; }
        float get_display_width() const { return al_get_display_width(display); }
        float get_display_height() const { return al_get_display_height(display); }

        float get_line_width() const { return line_dim; };
};

#endif