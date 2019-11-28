#ifndef LINEIMG_HPP
#define LINEIMG_HPP

#include"image.hpp"

class LineImage: public Image {
    
    private:
        ALLEGRO_BITMAP* intermediate_buffer;
        std::vector<Image*> subImages;
        std::map<float, std::pair<ALLEGRO_BITMAP*,ALLEGRO_BITMAP*>> frames;
        float position;
        float speed;
        float max_pos;

    protected:

    public:
        LineImage(float, float);
        LineImage(ALLEGRO_BITMAP*, float, float, bool);
        LineImage(const LineImage&);
        LineImage& operator=(const LineImage&);
        ~LineImage() override;

        void draw() override;
        void add(Image*);

        void update_position();

        void reset_position() { position = 0.0f; }

        void set_max(float m) { max_pos = m; }

        float get_position() const { return position; }

        float get_speed() const { return speed; }

        float get_max() const { return max_pos; }
};

#endif