#include"../../include/allegro_wrappers/lineimage.hpp"

LineImage::LineImage(float pos, float speed): 
Image(), subImages(), position(pos), speed(speed), max_pos(520.0f) {}

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

    ALLEGRO_BITMAP* buffer = al_get_target_bitmap();

    al_set_target_bitmap(bitmap);
    for(auto it : subImages)
        it->draw();

    int width  = al_get_bitmap_width(bitmap);
    int height = al_get_bitmap_height(bitmap);

    ALLEGRO_BITMAP* left  = al_create_sub_bitmap(bitmap, 0, 0, position, height);
    ALLEGRO_BITMAP* right = al_create_sub_bitmap(bitmap, position, 0, width - position, height);

    al_set_target_bitmap(buffer);

    al_draw_bitmap(left, x + width - position, y, 0);
    al_draw_bitmap(right, x, y, 0);

    al_destroy_bitmap(left);
    al_destroy_bitmap(right);
}

void LineImage::add(Image* it) {

    subImages.push_back(new Image(*it));
}

void LineImage::update_position() {
    
    position += speed;
    if(position > max_pos)
        position -= max_pos;     
}

void LineImage::reset_position() { position = 0.0f; }

void LineImage::set_max(float m) { max_pos = m; }

float LineImage::get_position() const { return position; }

float LineImage::get_speed() const { return speed; }