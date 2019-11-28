#include"../../include/gamelogic/line.hpp"

Line::Line(): img(new LineImage(0.0f, 0.5f)), objects() {

    std::cout << "\nLine initialization... ";

    auto context = Graphics::getInstance().get_initializer();

    std::cout << "Line initialization done.\n";
}

Line::Line(ALLEGRO_BITMAP* b, int index):
img(new LineImage(0.0f, 0.5f)), objects() {

    //std::cout << "\nLine initialization... ";

    img->set_bitmap(b);
    img->set_coordinates(0.0f, ((600/11)+1)*index);
    img->set_max(Graphics::getInstance().get_line_width());

    auto& context = Graphics::getInstance().get_initializer();

    float val = Graphics::getInstance().get_line_width();

    if(index%5 != 0)
    for(int i = 0; i < 4; ++i) {
        
        objects.push_back(new GameObject(0.0f, 0.0f, Collision::nd));
        auto it = objects.back();

        it->set_img(context[13]);
        it->get_img()->set_coordinates( 
            (((600/11)+1)/2.0f - 30/2.0f)+(val/4)*(i),
            (((600/11)+1)/2.0f - 30/2.0f));
        img->add(it->get_img());
    }

    //std::cout << "Line initialization done.\n";

}

Line::~Line() { 

    for(auto it : objects)
        delete it;
    delete img;
}

void Line::update() {
    
    img->update_position();

    for(auto& it : objects)
        it->update();
}

void Line::redraw() {

    Graphics::getInstance().schedule_drawing(img);
}

void Line::reset() {

    img->reset_position();

    for(auto& it : objects)
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