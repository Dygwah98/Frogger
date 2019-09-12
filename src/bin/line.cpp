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

bool Line::check_for_collision(const GameObject& g) const {
    
    for(const auto& it : objects)
    //va aggiunta una condizione che escluda le collisioni con entità benigne
    //if(is_deadly(it) and it.collides(g))
     if(it.collides(g))
        return true;
    
    return false;
}