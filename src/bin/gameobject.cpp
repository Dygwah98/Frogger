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

bool GameObject::collides(const GameObject& g) const {
    
    return false;
}
