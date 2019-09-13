#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"root.h"

class GameObject {

    private:
        //posizione nella linea (valore float -> pixel)
        float coord;
        //lunghezza sulla linea (valore float -> pixel)
        const float length;
        //definisce la "tipologia" di GameObject
        const char marker;

    protected:
    
    public:
        using gameobj_type = char;
        inline static string types = "LDA";

        GameObject();
        
        GameObject(float, float, char);
        
        virtual ~GameObject();

        void set_coord(float f) { coord = f; }

        float get_coord() const { return coord; }

        float get_length() const { return length; }

        char get_marker() const { return marker; }

        bool collides(const GameObject& g) const { return in_range<float>(coord, g.coord, coord + length); }
};

#endif