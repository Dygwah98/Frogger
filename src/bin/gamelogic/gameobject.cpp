#include"../../include/gamelogic/gameobject.h"

GameObject::GameObject(float f, float f2, Collision m): 
    img(nullptr), coord(f), length(f2), marker(m) {
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

}

void GameObject::update() {

}

void GameObject::redraw() {

    img->draw();
}

void GameObject::reset() {
    
}

Collision GameObject::collides(const GameObject& g) const { 
    
    return 
    in_range<float>(coord, g.coord, coord + length) 
        ? marker 
        : Collision::nd; 
}

void GameObject::set_img(Image* img) { this->img = img; }

Image* GameObject::get_img() const { 

    assert(img != nullptr);
    return img; 
}