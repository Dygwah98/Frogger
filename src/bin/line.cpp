#include"../include/line.h"

float Line::dim = 0;

const float& Line::getLineDimension() { 

    return Line::dim; 
}

void Line::setLineDimension(const float& f) { 

    Line::dim = f; 
}

Line::Line(): 
    head(0.0f), speed(0.0f), max_head_val(0.0f), objects() {

    cout << "Line::Line() " << this << endl;
}

Line::Line(const Line& l): 
    head(l.head), speed(l.speed), max_head_val(l.max_head_val), objects(l.objects) {

    cout << "Line::Line(const Line&) " << this << endl;
}

Line& Line::operator=(const Line& L) {
    
    if(this!=&L) {
        head = L.head;
        speed = L.speed;
        max_head_val = L.max_head_val;
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
    if(head >= max_head_val)
        head -= max_head_val;
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