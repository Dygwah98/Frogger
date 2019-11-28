#ifndef IMAGE_HPP
#define IMAGE_HPP

#include"../root.hpp"

class Image {

    private:
        bool deletable;
        bool is_bitmap_owner;

    protected:
        ALLEGRO_BITMAP* bitmap;
        float x;
        float y;

    public:
        Image();
        Image(ALLEGRO_BITMAP*, float, float, bool);
        Image(const Image&);
        Image& operator=(const Image&);
        virtual ~Image();

        virtual void draw();

        bool needs_freeing() const;
        float get_x() const;
        float get_y() const;

        void set_bitmap(int, int);
        void set_bitmap(std::string&&);
        void set_bitmap(ALLEGRO_BITMAP*);
        void set_deletable(bool);
        void set_coordinates(float, float);
        void set_x(float);
        void set_y(float);
};

#endif