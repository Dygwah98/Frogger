#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"root.h"

class GameObject {

    private:
        //posizione nella linea (valore float -> pixel)
        float coord;
        //lunghezza sulla linea (valore float -> pixel)
        float length;

    protected:
    
    public:
        
        GameObject();
        
        GameObject(const float&, const float&);
        
        virtual ~GameObject();

        void set_coord(const float& f) { coord = f; }

        const float& get_coord() const { return coord; }

        const float& get_length() const { return length; }

        bool collides(const GameObject&) const;
};

#endif