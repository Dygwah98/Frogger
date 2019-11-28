#ifndef LINE_HPP
#define LINE_HPP

#include"gameobject.h"

class Line {

    private:
        LineImage* img;
        std::vector<GameObject*> objects;

    protected:
    
    public:
        Line();
        Line(ALLEGRO_BITMAP*, int);
        ~Line();

        void update();
        void redraw();
        void reset();

        Collision collides(const GameObject&) const;

        float get_speed() const;
        void set_speed(float f) { img->set_speed(f); }
        void remove_nearest_to(float);
};

#endif