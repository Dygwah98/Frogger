#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"graphics.hpp"

class GameObject {

    private:    
        //posizione nella linea (valore float -> pixel)
        float coord;
        //lunghezza sulla linea (valore float -> pixel)
        float length;
        //definisce la "tipologia" di GameObject
        Collision marker;

    protected:
    
    public:
        static Collision null_val() { return Collision::nd; }

        GameObject(float, float, Collision);
        GameObject& operator=(const GameObject&);
        
        virtual ~GameObject();

        void set_coord(float f) { coord = f; }
        float get_coord() const { return coord; }

        void set_length(float l) { length = l; }
        float get_length() const { return length; }

        Collision collides(const GameObject&) const;
};

#endif