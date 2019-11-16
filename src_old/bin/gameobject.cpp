#include"../include/gameobject.h"

GameObject::GameObject(Graphics& g, float f, float f2, Collision m): 
    coord(f), length(f2), marker(m), graphic_context(g) {

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

Collision GameObject::collides(const GameObject& g) const { 
    
    return 
    in_range<float>(coord, g.coord, coord + length) 
        ? marker 
        : GameObject::null_val(); 
}