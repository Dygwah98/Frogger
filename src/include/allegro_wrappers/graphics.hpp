#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include"buffer.hpp"

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
        //restituisce i parametri adatti per l'inizializzazione del display
        ALLEGRO_DISPLAY_MODE getDispMode() const;
        //calcola i fattori di scala per questo particolare display
        void calc_scale_factors();

        Graphics();

    public:
        static Graphics& getInstance();

        static void delInstance();
        //dealloca le risorse di Allegro
        ~Graphics();
        //disegna gli elementi presenti nella queue, consumandoli se deletable
        void redraw();

        std::vector<ALLEGRO_BITMAP*>& get_initializer();

        void set_component(PanelType index) { buffer.set_component(index); }
        void schedule_drawing(Image* img) { buffer.queue.push_back(img); }
        void schedule_text(std::string s, int x, int y, ALLEGRO_COLOR c) { buffer.text.push_back({x, y, s, c}); }
        void clear() { buffer.clear(); }
        float get_buffer_width() const { return buffer.get_x(); }
        float get_buffer_height() const { return buffer.get_y(); }
        float get_refresh_rate() const { return 30.0f; }
        float get_display_width() const { return al_get_display_width(display); }
        float get_display_height() const { return al_get_display_height(display); }
        float get_line_width() const { return buffer.get_line_width(); }
        float get_line_height() const { return (600.0f/11.0f)+1.0f; }
};

#endif