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
    return GameComponent::get_exit_val();
}
