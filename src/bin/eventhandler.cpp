#include"../include/eventhandler.h"

EventHandler::EventHandler(Graphics& g): g(g), redraw(false), key_pressed(Keys::nd) {

    //inizializzazione timer:
    timer = al_create_timer(1.0/g.getDispMode().refresh_rate);
    assert(timer != nullptr);

    //inizializzazione coda degli eventi:
    event_queue = al_create_event_queue();
    assert(event_queue != nullptr);

    al_register_event_source(event_queue, al_get_display_event_source(g.display));
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

void EventHandler::launch() {

    if(is_ready()) return;

    al_flush_event_queue(event_queue);
    al_start_timer(timer);
    al_pause_event_queue(event_queue, false);
}

void EventHandler::suspend() {

    if(!is_ready()) return;
    //è una buona idea?
    g.clear();

    al_stop_timer(timer);
    al_flush_event_queue(event_queue);
    al_pause_event_queue(event_queue, true);
}

Event EventHandler::next_event() {

    Event ret = Event::nd;
    
    if(redraw and al_is_event_queue_empty(event_queue)) {
        redraw = false;
        return Event::Redraw;
    }

    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    const int& key = ev.keyboard.keycode;

    switch(ev.type) {
        
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
        
            ret = Event::Exit;
        
        break;
        
        case ALLEGRO_EVENT_DISPLAY_RESIZE:

            al_acknowledge_resize(g.display);
            g.calc_scale_factors();

        break;

        case ALLEGRO_EVENT_KEY_DOWN:
        
            if(contains<int, Keys>(keymap, key))
                key_pressed = keymap.at(key);
        
        break;

        case ALLEGRO_EVENT_KEY_UP:
        
            if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    ret = Event::Exit;
            
            else if(ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
                    ret = Event::Stop;

            else if(contains<int, Keys>(keymap, key))
                if(key_pressed == keymap.at(key))
                    key_pressed = Keys::nd;
        
        break;

        case ALLEGRO_EVENT_TIMER:
        
            if(!redraw) {
                ret = Event::Execute;
                redraw = true;        
            }
        
        break;

        default:
        break;
    }

    return ret;
}