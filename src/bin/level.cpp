#include"../include/level.h"

Level::Level(Graphics& g): GameComponent(), graphics(g), lines(), player() {

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}

map_type Level::type() { return 'l'; }

map_type Level::get_type() { return Level::type(); }

map_type Level::exec() {
    
    //qua va la partita
    bool STOP = false;
    
    graphics.launch();
    
    while(!STOP) {

        ALLEGRO_EVENT ev = graphics.next();
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE
        or (ev.type == ALLEGRO_EVENT_KEY_UP and ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
            STOP = true;
    }
    
    graphics.suspend();
    
    return GameComponent::get_exit_key();
}