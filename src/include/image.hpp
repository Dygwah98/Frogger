#ifndef IMAGE_HPP
#define IMAGE_HPP

#include"root.hpp"

class Image {

    private:
        ALLEGRO_BITMAP* bitmap;
        float x;
        float y;
        bool permanent;
        bool deletable;

    protected:

    public:
        Image();
        Image(ALLEGRO_BITMAP*, float, float, bool);
        Image(const Image&);
        Image& operator=(const Image&);
        virtual ~Image();

        virtual void draw();

        bool is_permanent() const;
        bool needs_freeing() const;
        float get_x() const;
        float get_y() const;

        void set_bitmap(int, int);
        void set_bitmap(std::string&&);

        void as_target();
};

class ComplexImage: public Image {

    private:
        std::vector<Image*> components;

    protected:

    public:
        ComplexImage();
        ComplexImage(ALLEGRO_BITMAP*, float, float, bool);
        ComplexImage(const ComplexImage&);
        ComplexImage& operator=(const ComplexImage&);
        ~ComplexImage() override;

        void draw() override;
};

#endif