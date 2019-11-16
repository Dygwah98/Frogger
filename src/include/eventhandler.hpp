#ifndef EVHANDLER_HPP
#define EVHANDLER_HPP

#include"graphics.hpp"

class EventHandler {
    
    private:
        
        inline static std::map<int, Keys> keymap = {
            {ALLEGRO_KEY_UP, Keys::UP}, 
            {ALLEGRO_KEY_LEFT, Keys::LEFT},
            {ALLEGRO_KEY_DOWN, Keys::DOWN},
            {ALLEGRO_KEY_RIGHT, Keys::RIGHT}
        };

        Graphics& g;

        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT_QUEUE* event_queue;

        bool redraw;
        Keys key_pressed;

    protected:

    public:
        EventHandler(Graphics&);
        ~EventHandler();

        Graphics& get_graphic_context() { return g; }
        //true se tutte le componenti sono valide per l'uso
        bool is_ready() const { return g.isValid and al_get_timer_started(timer) and !al_is_event_queue_paused(event_queue); }
        //avvia il timer e la coda degli eventi
        void launch();
        //stoppa il timer e la coda degli eventi
        void suspend();

        Event next_event();

        Keys next_key() { return key_pressed; }

};

#endif