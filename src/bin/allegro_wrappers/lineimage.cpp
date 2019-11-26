#include"../../include/allegro_wrappers/lineimage.hpp"

LineImage::LineImage(float pos, float speed): 
Image(), subImages(), position(pos), speed(speed), max_pos(-1.0f) {}

LineImage::LineImage(ALLEGRO_BITMAP* b, float x, float y, bool p, bool d):
Image(b, x, y, p, d), subImages(), position(0.0f), speed(1.0f), max_pos(520.0f) {}

LineImage::LineImage(const LineImage& limg): Image(limg), subImages() {

    for(auto it : limg.subImages)
        subImages.push_back(new Image(*it));
}

LineImage& LineImage::operator=(const LineImage& limg) {

    if(this != &limg) {
        Image::operator=(limg);
        for(auto it : limg.subImages)
            subImages.push_back(new Image(*it));
    }

    return *this;
}

LineImage::~LineImage() {

    for(auto it : subImages)
        delete it;
}

void LineImage::draw() {

    Image::draw();
}

void LineImage::add(Image* it) {

    subImages.push_back(new Image(*it));
}

void LineImage::update_position() {
    
    position += speed;
    position -= (position >= max_pos) ? max_pos : 0;     

}

void LineImage::reset_position() {

    position = 0.0f;
}

void LineImage::set_max(float m) {

    max_pos = m;
}

float LineImage::get_position() const { return position; }

float LineImage::get_speed() const { return speed; }