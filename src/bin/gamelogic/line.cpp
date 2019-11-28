#include"../../include/gamelogic/line.hpp"

Line::Line(): img(new LineImage(0.0f, 0.5f)), objects() {

    std::cout << "\nLine initialization... ";

    auto context = Graphics::getInstance().get_initializer();

    std::cout << "Line initialization done.\n";
}

Line::Line(ALLEGRO_BITMAP* b, int index):
img(new LineImage(0.0f, (index%5 == 0) ? 0.0f : 0.5f)), objects() {

    //std::cout << "\nLine initialization... ";

    img->set_bitmap(b);
    img->set_coordinates(0.0f, Graphics::getInstance().get_line_height()*index);
    img->set_max(Graphics::getInstance().get_line_width());

    auto& context = Graphics::getInstance().get_initializer();

    static float w = Graphics::getInstance().get_line_width();
    static float p = ((600/11)+1)/2.0f - 30/2.0f;
    static std::map<int, std::vector<std::tuple<float, float, Collision, float, int>>> obj_initializer = {
        {1,  { {p, p, Collision::Log, 90.0f, 15},    {p+w/4, p, Collision::Deadly, 30.0f, 14}, {p+3*(w/8), p, Collision::Log, 30.0f, 13},{p+w/2, p, Collision::Log, 90.0f, 15},        {p+3*(w/4), p, Collision::Log, 90.0f, 15} } },
        {2,  { {p, p, Collision::Deadly, 30.0f, 14}, {p+(w/8), p, Collision::Log, 30.0f, 13},  {p+w/4, p, Collision::Log, 90.0f, 15},    {p+w/2, p, Collision::Log, 90.0f, 15},        {p+3*(w/4), p, Collision::Log, 90.0f, 15} } },
        {3,  { {p, p, Collision::Log, 90.0f, 15},    {p+w/4, p, Collision::Log, 90.0f, 15},    {p+w/2, p, Collision::Log, 90.0f, 15},    {p+3*(w/4), p, Collision::Deadly, 30.0f, 14}, {p+7*(w/8), p, Collision::Log, 30.0f, 13} } },
        {4,  { {p, p, Collision::Log, 90.0f, 15},    {p+w/4, p, Collision::Log, 90.0f, 15},    {p+w/2, p, Collision::Deadly, 30.0f, 14}, {p+5*(w/8), p, Collision::Log, 30.0f, 13},    {p+3*(w/4), p, Collision::Log, 90.0f, 15} } },
        {6,  { {p, p, Collision::Deadly, 30.0f, 14}, {p+w/3, p, Collision::Deadly, 30.0f, 14}, {p+2*(w/3), p, Collision::Deadly, 30.0f, 14} } },
        {7,  { {p, p, Collision::Deadly, 30.0f, 14}, {p+w/3, p, Collision::Deadly, 30.0f, 14}, {p+2*(w/3), p, Collision::Deadly, 30.0f, 14} } },
        {8,  { {p, p, Collision::Deadly, 30.0f, 14}, {p+w/3, p, Collision::Deadly, 30.0f, 14}, {p+2*(w/3), p, Collision::Deadly, 30.0f, 14} } },
        {9,  { {p, p, Collision::Deadly, 30.0f, 14}, {p+w/3, p, Collision::Deadly, 30.0f, 14}, {p+2*(w/3), p, Collision::Deadly, 30.0f, 14} } },
        {10, { {p, p, Collision::Arrival, 30.0f, 1}, {p+w/3, p, Collision::Arrival, 30.0f, 1}, {p+2*(w/3), p, Collision::Arrival, 30.0f, 1} } }
    };

    if(index != 0 and index != 5)
    for(auto& oi : obj_initializer.at(index)) {
        
        GameObject* it = new GameObject(std::get<0>(oi), std::get<3>(oi), std::get<2>(oi));
        objects.push_back(it);

        it->set_img(context[std::get<4>(oi)]);
        it->get_img()->set_coordinates(std::get<0>(oi), std::get<1>(oi));
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
            temp += (img->get_max());
        
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