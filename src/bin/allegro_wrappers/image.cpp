#include"../../include/allegro_wrappers/image.hpp"

Image::Image(): bitmap(nullptr) {

}

Image::Image(ALLEGRO_BITMAP*, float, float, bool, bool) {

}

Image::Image(const Image& img):
permanent(img.permanent), deletable(img.deletable), bitmap(img.bitmap), x(img.x), y(img.y) {

}

Image& Image::operator=(const Image& img) {

    if(this != &img) {
        bitmap = img.bitmap;
        x = img.x;
        y = img.y;
        permanent = img.permanent;
        deletable = img.deletable;
    }

    return *this;
}

Image::~Image() {}

void Image::draw() {

    assert(bitmap != nullptr);
    al_draw_bitmap(bitmap, x, y, 0);
}

bool Image::is_permanent() const { return permanent; }
bool Image::needs_freeing() const { return deletable; }
float Image::get_x() const { return x; }
float Image::get_y() const { return y; }

void Image::set_bitmap(int w, int h) {

    if(bitmap != nullptr) al_destroy_bitmap(bitmap);

    bitmap = al_create_bitmap(w, h);
    x = w;
    y = h;
}

void Image::set_bitmap(std::string&& s) {

    if(bitmap != nullptr) al_destroy_bitmap(bitmap);

    bitmap = al_load_bitmap(s.data());
    x = al_get_bitmap_width(bitmap);
    y = al_get_bitmap_height(bitmap);
}

void Image::set_permanent(bool p) { permanent = p; }
void Image::set_deletable(bool d) { deletable = d; }
void Image::set_coordinates(float nx, float ny) { x = nx; y = ny; } 
void Image::set_x(float nx) { x = nx; }
void Image::set_y(float ny) { y = ny; }