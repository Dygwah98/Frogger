#include"../../include/allegro_wrappers/eventhandler.hpp"

EventHandler* EventHandler::instance = nullptr;

EventHandler& EventHandler::getInstance() {
    
    if(EventHandler::instance == nullptr)
        EventHandler::instance = new EventHandler();
    
    return *(EventHandler::instance);
}

void EventHandler::delInstance() {
    
    if(EventHandler::instance != nullptr)
        delete EventHandler::instance;
    EventHandler::instance = nullptr;
}

EventHandler::EventHandler(): 
    timer(nullptr), event_queue(nullptr), redraw(false), key_pressed(Keys::nd), new_key(Keys::nd) {

    std::cout << "\nEventHandler initialization... ";

    Graphics& g = Graphics::getInstance();
    //inizializzazione timer:
    timer = al_create_timer(1.0f/g.get_refresh_rate());
    assert(timer != nullptr);

    //inizializzazione coda degli eventi:
    event_queue = al_create_event_queue();
    assert(event_queue != nullptr);

    al_register_event_source(event_queue, al_get_display_event_source(g.display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_pause_event_queue(event_queue, true);

    std::cout << "EventHandler initialization done.\n";
}

EventHandler::~EventHandler() {

    if(timer       != nullptr) al_destroy_timer(timer);
    if(event_queue != nullptr) al_destroy_event_queue(event_queue);
}

void EventHandler::launch() {

    if(is_ready()) return;

    al_flush_event_queue(event_queue);
    al_pause_event_queue(event_queue, false);
    al_start_timer(timer);
}

void EventHandler::suspend() {

    if(!is_ready()) return;
    
    Graphics::getInstance().clear();
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
    do {
        
        al_wait_for_event(event_queue, &ev);

        switch(ev.type) {
        
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
        
                ret = Event::Exit;
        
            break;

            case ALLEGRO_EVENT_TIMER:
        
                if(!redraw) {
                    ret = Event::Execute;
                    redraw = true;        
                }

            break;
        
            case ALLEGRO_EVENT_DISPLAY_RESIZE:

                al_acknowledge_resize(Graphics::getInstance().display);
                Graphics::getInstance().calc_scale_factors();
                
            break;

            case ALLEGRO_EVENT_KEY_DOWN:
        
                if(contains<int, Keys>(keymap, ev.keyboard.keycode))
                    key_pressed = keymap.at(ev.keyboard.keycode);
                
            break;

            case ALLEGRO_EVENT_KEY_UP:
        
                if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                        ret = Event::Exit;
            
                else if(ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
                        ret = Event::Pause;

                else if(contains<int, Keys>(keymap, ev.keyboard.keycode))
                    if(key_pressed == keymap.at(ev.keyboard.keycode)) {
                        new_key = key_pressed;
                        key_pressed = Keys::nd;
                    }

            break;

            default:
            break;
        }
    } while(!al_is_event_queue_empty(event_queue));
    
    return ret;
}