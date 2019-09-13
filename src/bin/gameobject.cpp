#include"../include/gameobject.h"

GameObject::GameObject(): 
    coord(0.0f), length(0.0f), marker('_') {

    cout << "GameObject::GameObject() " << this << endl;
}

GameObject::GameObject(float f, float f2, char m): 
    coord(f), length(f2), marker(m) {

    cout << "GameObject::GameObject(float, float) " << this << endl;
}

GameObject& GameObject::operator=(const GameObject& G) {
    
    if(this!=&G) {
        coord = G.coord;
        length = G.length;
        marker = G.marker;
    }
    return *this;
}

GameObject::~GameObject() {

    cout << "GameObject::~GameObject() " << this << endl;
}
