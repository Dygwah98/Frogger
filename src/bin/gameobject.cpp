#include"../include/gameobject.h"

GameObject::GameObject(float f, float f2, Collision m): 
    coord(f), length(f2), marker(m) {

   std::cout << "GameObject::GameObject(float, float) " << this << std::endl;
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

    std::cout << "GameObject::~GameObject() " << this << std::endl;
}

Collision GameObject::collides(const GameObject& g) const { 
    
    return 
    in_range<float>(coord, g.coord, coord + length) 
        ? marker 
        : Collision::nd; 
}
