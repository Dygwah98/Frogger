#ifndef LINEIMG_HPP
#define LINEIMG_HPP

#include"image.hpp"

class LineImage: public Image {
    
    private:
        std::vector<Image*> subImages;
        float position;
        float speed;
        float max_pos;

    protected:

    public:
        LineImage(float, float);
        LineImage(ALLEGRO_BITMAP*, float, float, bool, bool);
        LineImage(const LineImage&);
        LineImage& operator=(const LineImage&);
        ~LineImage() override;

        void draw() override;
        void add(Image*);

        void set_max(float);

        float get_position() const;
        float get_speed() const;
        void update_position();
        void reset_position();
};

#endif