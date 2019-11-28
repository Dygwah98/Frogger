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
    img->set_coordinates(0.0f, Graphics::getInstance().get_line_height()*index);
    img->set_max(Graphics::getInstance().get_line_width());

    auto& context = Graphics::getInstance().get_initializer();

    static float w = Graphics::getInstance().get_line_width();
    static float p = ((600/11)+1)/2.0f - 30/2.0f;
    static std::map<int, std::vector<std::tuple<float, float, Collision>>> obj_initializer = {
        {1,  { {p, p, Collision::Log},     {p+w/4, p, Collision::Deadly},  {p+w/2, p, Collision::Log},     {p+3*(w/4), p, Collision::Log}     } },
        {2,  { {p, p, Collision::Deadly},  {p+w/4, p, Collision::Log},     {p+w/2, p, Collision::Log},     {p+3*(w/4), p, Collision::Log}     } },
        {3,  { {p, p, Collision::Log},     {p+w/4, p, Collision::Log},     {p+w/2, p, Collision::Log},     {p+3*(w/4), p, Collision::Deadly}  } },
        {4,  { {p, p, Collision::Log},     {p+w/4, p, Collision::Log},     {p+w/2, p, Collision::Deadly},  {p+3*(w/4), p, Collision::Log}     } },
        {6,  { {p, p, Collision::Deadly},  {p+w/4, p, Collision::Deadly},  {p+w/2, p, Collision::Deadly},  {p+3*(w/4), p, Collision::Deadly}  } },
        {7,  { {p, p, Collision::Deadly},  {p+w/4, p, Collision::Deadly},  {p+w/2, p, Collision::Deadly},  {p+3*(w/4), p, Collision::Deadly}  } },
        {8,  { {p, p, Collision::Deadly},  {p+w/4, p, Collision::Deadly},  {p+w/2, p, Collision::Deadly},  {p+3*(w/4), p, Collision::Deadly}  } },
        {9,  { {p, p, Collision::Deadly},  {p+w/4, p, Collision::Deadly},  {p+w/2, p, Collision::Deadly},  {p+3*(w/4), p, Collision::Deadly}  } },
        {10, { {p, p, Collision::Arrival}, {p+w/4, p, Collision::Arrival}, {p+w/2, p, Collision::Arrival}, {p+3*(w/4), p, Collision::Arrival} } }
    };

    if(index != 0 and index != 5)
    for(int i = 0; i < 4; ++i) {
        
        GameObject* it = new GameObject(std::get<0>(obj_initializer.at(index)[i]), 30.0f, std::get<2>(obj_initializer.at(index)[i]));
        objects.push_back(it);

        if(std::get<2>(obj_initializer.at(index)[i]) != Collision::Deadly)
            it->set_img(context[13]);
        else
            it->set_img(context[14]);

        it->get_img()->set_coordinates( 
            std::get<0>(obj_initializer.at(index)[i]),
            std::get<1>(obj_initializer.at(index)[i]));
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

    float temp;
    for(auto& it : objects) {

        it->update();

        temp = it->get_coord() - img->get_speed();
        if(temp < 0)
            temp += (img->get_max() - it->get_length());
        
        it->set_coord(temp);
    }
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

    if(!objects.empty()) {
        auto it = std::find_if(objects.begin(), objects.end(), [&](auto& el) { 
            return el->collides(in) != Collision::nd; 
        });

        return it != objects.end() ? (**it).collides(in) : Collision::nd;
    }

    return Collision::nd;
}

float Line::get_speed() const { return img->get_speed(); }