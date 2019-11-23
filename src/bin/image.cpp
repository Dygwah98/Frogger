#include"../include/image.hpp"

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

void Image::as_target() {

    al_set_target_bitmap(bitmap);
}