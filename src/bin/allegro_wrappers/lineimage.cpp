#include"../../include/allegro_wrappers/lineimage.hpp"

LineImage::LineImage(): Image(), subImages() {}
LineImage::LineImage(ALLEGRO_BITMAP* b, float x, float y, bool p, bool d):
Image(b, x, y, p, d), subImages() {}

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

}

void LineImage::add(Image* it) {

    subImages.push_back(new Image(*it));
}