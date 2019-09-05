#include"../include/gameobject.h"

GameObject::GameObject(): 
    coord(0.0f) {

    cout << "GameObject::GameObject() " << this << endl;
}

GameObject::GameObject(const float& f): 
    coord(f) {}

GameObject::~GameObject() {

    cout << "GameObject::~GameObject() " << this << endl;
}

void GameObject::set_coord(const float& f) {

    coord = f;
}

const float& GameObject::get_coord() const {

    return coord;
}

bool GameObject::collides(const GameObject& g) const {
    
    return false;
}
