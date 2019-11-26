#include"../../include/allegro_wrappers/lineimage.hpp"

LineImage::LineImage() {}
LineImage::LineImage(ALLEGRO_BITMAP*, float, float, bool, bool) {}

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

LineImage::~LineImage() {}

void LineImage::draw() {}
void LineImage::add(Image*) {}