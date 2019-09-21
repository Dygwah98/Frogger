#include"../include/line.h"

float Line::dim = 0;

const float& Line::getLineDimension() { 

    return Line::dim; 
}

void Line::setLineDimension(const float& f) { 

    Line::dim = f; 
}

Line::Line(): 
    graphic_index(-1), head(0.0f), speed(1.0f), objects() {

    cout << "Line::Line() " << this << endl;
}

Line::Line(const Line& l): 
    graphic_index(l.graphic_index), head(l.head), speed(l.speed), objects(l.objects) {

    cout << "Line::Line(const Line&) " << this << endl;
}

Line& Line::operator=(const Line& L) {
    
    if(this!=&L) {
        head = L.head;
        speed = L.speed;
        objects = L.objects;
    }
    return *this;
}

Line::~Line() {

    cout << "Line::~Line() " << this << endl;
}

const GameObject& Line::at(unsigned index) const {

    assert(index < objects.size());
    return objects[index];
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