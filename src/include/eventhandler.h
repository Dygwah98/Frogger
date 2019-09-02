#ifndef EVHANDLER_H
#define EVHANDLER_H

#include"graphics.h"

enum struct Event : int { nd = -1, Exit = 0, Execute = 1, Redraw = 2 };
enum struct Keys  : int { nd = -1, UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };

class EventHandler {
    
    private:
        
        inline static map<int, Keys> keymap = {
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

        Graphics& get_graphic_context();
        //true se tutte le componenti sono valide per l'uso
        bool is_ready() const;
        //avvia il timer e la coda degli eventi
        void launch();
        //stoppa il timer e la coda degli eventi
        void suspend();

        Event next_event();

        Keys next_key();

};

#endif