#include"../../include/gamelogic/line.hpp"

Line::Line(): img(new LineImage(0.0f, 1.0f)), objects() {

    std::cout << "\nLine initialization... ";

    auto context = Graphics::getInstance()->get_initializer();

    for(int i = 0; i < 6; ++i)
        objects.push_back(new GameObject(0.0f, 0.0f, Collision::nd));
    img->set_max(objects.size());

    for(auto it : objects) {
        it->set_img(context[1]);
        img->add(it->get_img());
    }

    std::cout << "Line initialization done.\n";
}

Line::Line(ALLEGRO_BITMAP* b, int index):
img(new LineImage(0.0f, 1.0f)), objects() {

    //std::cout << "\nLine initialization... ";

    img->set_bitmap(b);
    img->set_coordinates(0.0f, ((600/11)+1)*index);

    auto context = Graphics::getInstance()->get_initializer();

    if(index%5 != 0)
    for(int i = 0; i < 6; ++i) {
        
        objects.push_back(new GameObject(0.0f, 0.0f, Collision::nd));
        auto it = objects.back();

        it->set_img(context[1]);
        it->get_img()->set_coordinates( 
            (((600/11)+1)/2.0f - 30/2.0f)+(Graphics::getInstance()->get_line_width()/6)*(i),
            (((600/11)+1)/2.0f - 30/2.0f));
        img->add(it->get_img());
    }

    //std::cout << "Line initialization done.\n";

}

Line::~Line() {

    delete img;
}

void Line::update() {
    
    img->update_position();

    for(auto it : objects)
        it->update();
}

void Line::redraw() {

    Graphics::getInstance()->schedule_drawing(img);
}

void Line::reset() {

    img->reset_position();

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

float Line::get_speed() const { return img->get_speed(); }