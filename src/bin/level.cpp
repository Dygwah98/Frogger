#include"../include/level.h"

Level::Level(Graphics& g): GameComponent(), graphics(g), lines(), player() {

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}

GameComponent::map_type Level::type() { return GameComponent::types[2]; }

GameComponent::map_type Level::get_type() { return Level::type(); }

GameComponent::map_type Level::exec() {

    //qua va la partita
    bool STOP = false;
    
    graphics.launch();
    
    while(!STOP) {

        const auto& ev = graphics.next();
        switch(ev) {
            case Graphics::Event::Exit:
                STOP = true;
                break;

            case Graphics::Event::Execute:
                break;

            case Graphics::Event::Redraw:
                break;
            
            default:
                break;
        }
    }
    
    graphics.suspend();
    
    return GameComponent::exit_val();
}