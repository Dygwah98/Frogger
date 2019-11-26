#ifndef LINEIMG_HPP
#define LINEIMG_HPP

#include"image.hpp"

class LineImage: public Image {
    
    private:
        std::vector<Image*> subImages;

    protected:

    public:
        LineImage();
        LineImage(ALLEGRO_BITMAP*, float, float, bool, bool);
        LineImage(const LineImage&);
        LineImage& operator=(const LineImage&);
        ~LineImage() override;

        void draw() override;
        void add(Image*);
};

#endif