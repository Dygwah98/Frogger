#include"../../include/gamelogic/line.hpp"

Line::Line(): img(new LineImage()), objects(), position(0.0f), speed(1.0f) {

    std::cout << "\nLine initialization... ";

    auto context = Graphics::getInstance()->get_initializer();

    for(int i = 0; i < 6; ++i)
        objects.push_back(new GameObject(0.0f, 0.0f, Collision::nd));

    for(auto it : objects) {
        it->set_img(context[1]);
        img->add(it->get_img());
    }

    std::cout << "Line initialization done.\n";
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

Collision Line::collides(const GameObject& in) const {

    auto it = 
    std::find_if(objects.begin(), objects.end(), [&](auto el) { 
        return in.collides(*el) != Collision::nd; 
    });

    return it != objects.end() ? in.collides(**it) : Collision::nd;
}

float Line::get_speed() const { return speed; }