#include"../include/animatedobj.hpp"

AnimatedGameObject::AnimatedGameObject(float a, float b, Collision c, std::vector<int>&& bitmaps): 
    GameObject(a, b, c), bitmaps(bitmaps), actual(0) {

}

AnimatedGameObject::AnimatedGameObject(const AnimatedGameObject& a): 
    GameObject(a), bitmaps(a.bitmaps), actual(0) {

}

AnimatedGameObject& AnimatedGameObject::operator=(const AnimatedGameObject& a) {

    if(this != &a) {
        GameObject::operator=(a);
        bitmaps = a.bitmaps;
        actual = 0;
    }

    return *this;
}

void AnimatedGameObject::reset_gindex() { 

    actual = 0; 
}

void AnimatedGameObject::update_gindex() {

    actual = (++actual) % bitmaps.size();
}

int AnimatedGameObject::get_gindex() const { 

    return bitmaps[actual]; 
}