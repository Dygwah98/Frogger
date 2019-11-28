#ifndef ANIMG_HPP
#define ANIMG_HPP

#include"image.hpp"

class AnimatedImage: public Image {

    private:
        std::map<int, Image*> components;
        int actual;

    protected:

    public:
        AnimatedImage();
        AnimatedImage(ALLEGRO_BITMAP*, float, float, bool);
        AnimatedImage(const AnimatedImage&);
        AnimatedImage& operator=(const AnimatedImage&);
        ~AnimatedImage() override;

        void draw() override;
        void add(int, Image*);

        void reset_gindex();
        void update_gindex();
        int get_gindex() const;
};

#endif