#include"../include/gameobject.h"

GameObject::GameObject(): position(0.0f) {

    cout << "GameObject::GameObject() " << this << endl;
}

GameObject::GameObject(const float& f): position(f) {}

bool GameObject::collides(const GameObject& g) const {
    return false;
}

GameObject::~GameObject() {

    cout << "GameObject::~GameObject() " << this << endl;
}

