#include"../include/gameobject.h"

GameObject::GameObject(): 
    coord(0.0f), length(0.0f) {

    cout << "GameObject::GameObject() " << this << endl;
}

GameObject::GameObject(const float& f, const float& f2): 
    coord(f), length(f2) {}

GameObject::~GameObject() {

    cout << "GameObject::~GameObject() " << this << endl;
}

bool GameObject::collides(const GameObject& g) const {
    
    return in_range<float>(coord, g.get_coord(), coord + length);
}
