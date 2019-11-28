#ifndef EVHANDLER_HPP
#define EVHANDLER_HPP

#include"graphics.hpp"

class EventHandler {
    
    private:
        static EventHandler* instance;

        inline static std::map<int, Keys> keymap = {
            {ALLEGRO_KEY_UP, Keys::UP}, 
            {ALLEGRO_KEY_LEFT, Keys::LEFT},
            {ALLEGRO_KEY_DOWN, Keys::DOWN},
            {ALLEGRO_KEY_RIGHT, Keys::RIGHT},
            {ALLEGRO_KEY_ENTER, Keys::ENTER}
        };

        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT_QUEUE* event_queue;

        bool redraw;
        Keys key_pressed;
        Keys new_key;

        EventHandler();

    public:
        static EventHandler& getInstance();
        static void delInstance();

        ~EventHandler();

        //true se tutte le componenti sono valide per l'uso
        bool is_ready() const { 
        
            return Graphics::getInstance().initAllegro() and 
                al_get_timer_started(timer) and 
                !al_is_event_queue_paused(event_queue); 
        }
        //avvia il timer e la coda degli eventi
        void launch();
        //stoppa il timer e la coda degli eventi
        void suspend();

        Event next_event();

        Keys next_key() { 

            Keys temp = new_key;
            new_key = Keys::nd;
            return temp; 
        }

        std::string get_time() const { return std::to_string(al_get_timer_count(timer)/60); }
};

#endif