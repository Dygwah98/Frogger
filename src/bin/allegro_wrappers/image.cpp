#include"../../include/allegro_wrappers/image.hpp"

Image::Image(): deletable(false), is_bitmap_owner(false), bitmap(nullptr), x(-1.0f), y(-1.0f) {}

Image::Image(ALLEGRO_BITMAP* _bitmap, float _x, float _y, bool _d):
deletable(_d), is_bitmap_owner(false), bitmap(_bitmap), x(_x), y(_y) {}

Image::Image(const Image& img):
deletable(img.deletable), is_bitmap_owner(false), bitmap(img.bitmap), x(img.x), y(img.y) {}

Image& Image::operator=(const Image& img) {

    if(this != &img) {
        bitmap = img.bitmap;
        x = img.x;
        y = img.y;
        deletable = img.deletable;
    }

    return *this;
}

Image::~Image() {

    if(is_bitmap_owner) al_destroy_bitmap(bitmap);
}

void Image::draw() {

    assert(x != -1.0f and y != -1.0f);
    if(bitmap != nullptr)
        al_draw_bitmap(bitmap, x, y, 0);
}

bool Image::needs_freeing() const { return deletable; }
float Image::get_x() const { return x; }
float Image::get_y() const { return y; }

void Image::set_bitmap(int w, int h) {

    if(bitmap != nullptr and is_bitmap_owner)
        al_destroy_bitmap(bitmap);

    bitmap = al_create_bitmap(w, h);
    x = w;
    y = h;
    is_bitmap_owner = true;
}

void Image::set_bitmap(std::string&& s) {

    if(bitmap != nullptr and is_bitmap_owner)
        al_destroy_bitmap(bitmap);

    bitmap = al_load_bitmap(s.data());
    x = al_get_bitmap_width(bitmap);
    y = al_get_bitmap_height(bitmap);    
    is_bitmap_owner = true;
}

void Image::set_bitmap(ALLEGRO_BITMAP* b) {

    if(bitmap != nullptr and is_bitmap_owner)
        al_destroy_bitmap(bitmap);

    bitmap = b;
    x = al_get_bitmap_width(bitmap);
    y = al_get_bitmap_height(bitmap);
    is_bitmap_owner = false;
}

void Image::set_deletable(bool d) { deletable = d; }
void Image::set_coordinates(float nx, float ny) { x = nx; y = ny; } 
void Image::set_x(float nx) { x = nx; }
void Image::set_y(float ny) { y = ny; }