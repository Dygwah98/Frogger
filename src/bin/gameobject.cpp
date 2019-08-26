#include"../include/gameobject.h"

GameObject::GameObject(): line(0), position(0.0f) {}

GameObject::GameObject(const int& i, const float& f): line(i), position(f) {}

bool GameObject::collides(const GameObject& g) const {
    return false;
}

GameObject::~GameObject() {}

