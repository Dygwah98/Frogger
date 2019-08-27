#include"../include/level.h"

Level::Level(Graphics& g): GameComponent(), graphics(g), lines(), player() {

    cout << "Level::Level() " << this << endl;
}

Level::~Level() {

    cout << "Level::~Level() " << this << endl;
}