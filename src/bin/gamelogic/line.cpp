#include"../../include/gamelogic/line.hpp"

Line::Line(): img(new LineImage()), objects(), position(0.0f), speed(1.0f) {

    for(int i = 0; i < 6; ++i)
        objects.push_back(new GameObject(0.0f, 0.0f, Collision::nd));

    for(auto it : objects)
        img->add(it->get_img());
}

Line::~Line() {

    delete img;
}

void Line::update() {
    
    position += speed;
    position -= (position >= objects.size()) ? objects.size() : 0;     

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