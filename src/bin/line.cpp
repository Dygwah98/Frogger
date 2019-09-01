#include"../include/line.h"

float Line::dim = 0;

const float& Line::getLineDimension() { 

    return Line::dim; 
}

void Line::setLineDimension(const float& f) { 

    Line::dim = f; 
}

Line::Line(): head(0.0f), objects() {}

Line::Line(const Line& l): head(l.head), objects() {}

void Line::shift_head() {}

bool Line::check_for_collision(const GameObject& g) const {
    
    for(const auto& it : objects) {
        //verifica se l'oggetto collide coll'input
    }
    
    return false;
}