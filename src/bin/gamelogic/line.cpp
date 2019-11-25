#include"../../include/gamelogic/line.hpp"

Line::Line(): img(new LineImage()), objects() {

    //va inizializzato objects
    for(auto it : objects)
        img->add(it->get_img());
}

Line::~Line() {

    delete img;
}

void Line::update() {

    float temp = position + speed;
    position = temp;
    position = position % objects.size();
    
    for(auto it : objects)
        it->update();
}

void Line::redraw() {

    img->draw();
}

void Line::reset() {

    position = 0;

    for(auto it : objects)
        it->reset();
}

Collision Line::collides(const GameObject&) const {

}

float Line::get_speed() const { return speed; }