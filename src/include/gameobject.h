#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"root.h"

class GameObject {

    private:
        //posizione nella linea (valore float -> pixel)
        float coord;

    protected:
    
    public:
        
        GameObject();
        
        GameObject(const float&);
        
        virtual ~GameObject();

        void set_coord(const float&);

        const float& get_coord() const;

        bool collides(const GameObject&) const;
};

#endif