#ifndef LINE_H
#define LINE_H

#include"gameobject.h"
/*
    rappresenta una riga dell'area di gioco
    - si limita a contenere una rappresentazione minimale dei vari oggetti
        - identificativo per il tipo + lungezza dell'oggetto   
            - si potrebbero usare anche oggetti a dimensione fissa
    - può verificare se in una data posizione si verifica una collisione

    interfaccia leggera e semplice, così da nascondere la complessità interna

    PROBLEMA: diventa complicato gestire nemici con comportamenti complessi, o con più stati
*/
class Line {

    private:
        //pixel length of a Line on screen
        static float dim;

        Graphics& graphics;

        int graphic_index;
        //offset sulle posizioni: in ogni momento, la posizione reale di ogni elemento sarà ( positions[i] + head ) % dim
        float head;
        
        float speed;
    
        vector<GameObject> objects;
    
    protected:
    
    public:
        //getter for the length of a line
        static const float& getLineDimension();
        //setter for the length of a line
        static void setLineDimension(const float&);
        
        Line(Graphics&);
        
        Line(const Line&);

        Line& operator=(const Line&);

        ~Line();

        const GameObject& at(float) const;

        void shift_head();

        Collision check_for_collision(const GameObject&) const;

        void place(float, float, Collision);

        void set_gindex(int i) { graphic_index = i; }

        int get_gindex() const { return graphic_index; }

        float get_speed() const { return speed; }

        float get_head() const { return head; }
};

#endif