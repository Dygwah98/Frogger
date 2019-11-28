#include"../../include/allegro_wrappers/animatedimage.hpp"

AnimatedImage::AnimatedImage(): 
Image(), components(), actual(0) {}

AnimatedImage::AnimatedImage(ALLEGRO_BITMAP* b, float x, float y, bool d): 
Image(b, x, y, d), components(), actual(0) {}

AnimatedImage::AnimatedImage(const AnimatedImage& aimg): 
Image(aimg), components(aimg.components), actual(0) {}

AnimatedImage& AnimatedImage::operator=(const AnimatedImage& aimg) {

    if(this != &aimg) {
        Image::operator=(aimg);
        components = aimg.components;
        actual = 0;
    }

    return *this;
}

AnimatedImage::~AnimatedImage() {
}

void AnimatedImage::draw() {

    Image::draw();
}

void AnimatedImage::add(int K, Image* V) {

    components.insert({K, V});
}

void AnimatedImage::reset_gindex() {

}

void AnimatedImage::update_gindex() {

}

int AnimatedImage::get_gindex() const {

}