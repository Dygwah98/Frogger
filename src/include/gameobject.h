#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"root.h"

class GameObject {

    private:
        //quest'oggetto con la bitmap corrispondente (in Graphics)
        int graphic_index;
        //posizione nella linea (valore float -> pixel)
        float coord;
        //lunghezza sulla linea (valore float -> pixel)
        float length;
        //definisce la "tipologia" di GameObject
        Collision marker;

    protected:

    public:
        static Collision null_val() { return Collision::nd; }

        GameObject();
        
        GameObject(int, float, float, Collision);

        GameObject& operator=(const GameObject&);
        
        virtual ~GameObject();

        void set_gindex(int i) { graphic_index = i; }

        int get_gindex() const { return graphic_index; }

        void set_coord(float f) { coord = f; }

        float get_coord() const { return coord; }

        void set_length(float l) { length = l; }

        float get_length() const { return length; }

        Collision collides(const GameObject&) const;
};

#endif