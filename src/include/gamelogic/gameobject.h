#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include"../allegro_wrappers/graphics.hpp"
#include"../allegro_wrappers/animatedimage.hpp"
#include"../allegro_wrappers/lineimage.hpp"

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
        virtual void update();
        virtual void redraw();
        virtual void reset();

        void set_coord(float f) { coord = f; }
        float get_coord() const { return coord; }

        void set_length(float l) { length = l; }
        float get_length() const { return length; }
        
        void set_img(ALLEGRO_BITMAP*);
        Image* get_img() const;

        Collision collides(const GameObject&) const;
};

#endif