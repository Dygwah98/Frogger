#include"../include/line.h"

float Line::dim = 0;

const float& Line::getLineDimension() { 

    return Line::dim; 
}

void Line::setLineDimension(const float& f) { 

    Line::dim = f; 
}

Line::Line(Graphics& g): 
    graphics(g), graphic_index(-1), head(0.0f), speed(1.0f), objects() {

    cout << "Line::Line() " << this << endl;
}

Line::Line(const Line& l): 
    graphics(l.graphics), graphic_index(l.graphic_index), head(l.head), speed(l.speed), objects(l.objects) {

    cout << "Line::Line(const Line&) " << this << endl;
}

Line& Line::operator=(const Line& L) {
    
    if(this!=&L) {
        graphics = L.graphics;
        head = L.head;
        speed = L.speed;
        objects = L.objects;
    }
    return *this;
}

Line::~Line() {

    cout << "Line::~Line() " << this << endl;
}

const GameObject& Line::at(float key) const {

    assert(!objects.empty());
    assert(key > objects[0].get_coord());
    assert(key < objects[objects.size()-1].get_coord() + objects[objects.size()-1].get_length());

    int index = objects.size()/2;
    const GameObject* ret = &(objects[index]);
    
    for(size_t i = 0; i < objects.size(); ++i) {
        
        if(key < objects[index].get_coord())    
            index -= index/2;
        else if(key > objects[index].get_coord() + objects[index].get_length())
            index += index/2;
        else {
            ret = &(objects[index]);
            break;
        }
    }

    return *ret;
}

void Line::shift_head() {

    head += speed;
    if(head >= Line::getLineDimension())
        head -= Line::getLineDimension();
}

Collision Line::check_for_collision(const GameObject& g) const {
    
    Collision temp = GameObject::null_val();
    
    for(const auto& it : objects) {
        temp = it.collides(g);
        if(temp != GameObject::null_val())
            return temp;
    }
    return temp;
}

void Line::place(float coord, float length, Collision marker) {

    //Inserisci un GameObject, se necessario sloggia il precedente
}