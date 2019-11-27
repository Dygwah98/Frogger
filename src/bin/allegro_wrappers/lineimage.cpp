#include"../../include/allegro_wrappers/lineimage.hpp"

LineImage::LineImage(float pos, float speed): 
Image(), intermediate_buffer(nullptr), subImages(), position(pos), speed(speed), max_pos(520.0f) {}

LineImage::LineImage(ALLEGRO_BITMAP* b, float x, float y, bool p, bool d):
Image(b, x, y, p, d), intermediate_buffer(nullptr), subImages(), position(0.0f), speed(2.0f), max_pos(520.0f) {}

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

    ALLEGRO_BITMAP* buffer = al_get_target_bitmap();

    intermediate_buffer = al_clone_bitmap(bitmap);
    al_set_target_bitmap(intermediate_buffer);
    for(auto it : subImages)
        it->draw();

    int width  = al_get_bitmap_width(bitmap);
    int height = al_get_bitmap_height(bitmap);

    al_set_target_bitmap(buffer);
    al_draw_bitmap_region(intermediate_buffer, 0, 0, position, height, x + width - position, y, 0);
    al_draw_bitmap_region(intermediate_buffer, position, 0, width - position, height, x, y, 0);

    al_destroy_bitmap(intermediate_buffer);
}

void LineImage::add(Image* it) {

    subImages.push_back(new Image(*it));
}

void LineImage::update_position() {
    
    position += speed;
    if(position >= max_pos)
        position -= max_pos;     
}

void LineImage::reset_position() { position = 0.0f; }

void LineImage::set_max(float m) { max_pos = m; }

float LineImage::get_position() const { return position; }

float LineImage::get_speed() const { return speed; }