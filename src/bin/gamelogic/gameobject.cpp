#include"../../include/gamelogic/gameobject.h"

GameObject::GameObject(float f, float f2, Collision m): 
img(nullptr), coord(f), length(f2), marker(m) {

    img = new Image(nullptr, f, 0.0f, false, false);
}

GameObject& GameObject::operator=(const GameObject& G) {
    
    if(this!=&G) {
        coord = G.coord;
        length = G.length;
        marker = G.marker;
    }
    return *this;
}

GameObject::~GameObject() { delete img; }

void GameObject::update() {}

void GameObject::redraw() { Graphics::getInstance()->schedule_drawing(img); }

void GameObject::reset() {}

Collision GameObject::collides(const GameObject& g) const { 
    
    return 
    in_range<float>(coord, g.coord, coord + length) 
        ? marker 
        : Collision::nd; 
}

void GameObject::set_img(ALLEGRO_BITMAP* bitmap) { 

    img->set_bitmap(bitmap); 
}

Image* GameObject::get_img() const { 

    assert(img != nullptr);
    return img; 
}