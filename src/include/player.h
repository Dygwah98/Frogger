#ifndef PLAYER_H
#define PLAYER_H

#include"gameobject.h"

class Player: public GameObject {

    private:
        //posizione sulla mappa (linea)
        int position;
        //true se il player è in movimento
        bool isMoving;
        //numero di vite del player
        int lifes;

    protected:
    
    public:
        Player();
        Player(const int&, const float&);
        virtual ~Player();

        int get_position() const;

        bool is_moving() const;

        bool is_dead() const;

        void lose_life();

        void reposition(const int&, const float&);
};

#endif