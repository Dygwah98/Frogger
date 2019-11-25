#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"../allegro_wrappers/graphics.hpp"
#include"../allegro_wrappers/image.hpp"

class GameObject {

    private:    
        Image* img;
        //posizione nella linea (valore float -> pixel)
        float coord;
        //lunghezza sulla linea (valore float -> pixel)
        float length;
        //definisce la "tipologia" di GameObject
        Collision marker;

    protected:
    
    public:
        GameObject(float, float, Collision);
        GameObject& operator=(const GameObject&);
        
        virtual ~GameObject();
        virtual void update() = 0;
        virtual void redraw() = 0;
        virtual void reset()  = 0;

        void set_coord(float f) { coord = f; }
        float get_coord() const { return coord; }

        void set_length(float l) { length = l; }
        float get_length() const { return length; }
        
        void set_img();
        Image* get_img() const;

        Collision collides(const GameObject&) const;
};

#endif