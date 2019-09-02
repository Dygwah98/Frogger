#include"../include/eventhandler.h"

EventHandler::EventHandler(Graphics& g): g(g) {

    //inizializzazione timer:
    timer = al_create_timer(1.0/g.getDispMode().refresh_rate);
    assert(timer != nullptr);

    //inizializzazione coda degli eventi:
    event_queue = al_create_event_queue();
    assert(event_queue != nullptr);

    al_register_event_source(event_queue, al_get_display_event_source(g.get_display()));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_pause_event_queue(event_queue, true);

    cout << "EventHandler::EventHandler() " << this << endl;
}

EventHandler::~EventHandler() {

    if(timer       != nullptr) al_destroy_timer(timer);
    if(event_queue != nullptr) al_destroy_event_queue(event_queue);

    cout << "EventHandler::~EventHandler() " << this << endl;
}

Graphics& EventHandler::get_graphic_context() {

    return g;
}

bool EventHandler::is_ready() const {

    return g.isValid and al_get_timer_started(timer) and !al_is_event_queue_paused(event_queue);
}

void EventHandler::launch() {

    if(is_ready()) return;

    al_flush_event_queue(event_queue);
    al_start_timer(timer);
    al_pause_event_queue(event_queue, false);
}

void EventHandler::suspend() {

    if(!is_ready()) return;
    
    al_stop_timer(timer);
    al_flush_event_queue(event_queue);
    al_pause_event_queue(event_queue, true);
}

Event EventHandler::next_event() {

    Event ret = Event::nd;
    
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    
    switch(ev.type) {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            ret = Event::Exit;
        break;

        case ALLEGRO_EVENT_KEY_DOWN:
        
            if(EventHandler::keymap.find(ev.keyboard.keycode) != EventHandler::keymap.end())
                key_pressed = EventHandler::keymap.at(ev.keyboard.keycode);
        
        break;

        case ALLEGRO_EVENT_KEY_UP:
        
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    ret = Event::Exit;
            else if(EventHandler::keymap.find(ev.keyboard.keycode) != EventHandler::keymap.end())
                if(key_pressed == EventHandler::keymap.at(ev.keyboard.keycode))
                    key_pressed = Keys::nd;
        
        break;

        case ALLEGRO_EVENT_TIMER:
        
            if(!redraw) {
                ret = Event::Execute;
                redraw = true;
            
            } else if(al_is_event_queue_empty(event_queue)) {
                ret = Event::Redraw;
                redraw = false;
            }
        
        break;

        default:
        break;
    }

    return ret;
}

Keys EventHandler::next_key() {

    return key_pressed;
}