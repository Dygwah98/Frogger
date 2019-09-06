#ifndef PLAYER_H
#define PLAYER_H

#include"gameobject.h"

class Player: public GameObject {

    private:

        inline static map<Keys, int> dpos = {
            {Keys::nd, 0},
            {Keys::UP, -1},
            {Keys::LEFT, 0},
            {Keys::DOWN, +1},
            {Keys::RIGHT, 0}
        };

        inline static map<Keys, float> dcord = {
            {Keys::nd, 0.0f},
            {Keys::UP, 0.0f}, 
            {Keys::LEFT, -1.0f}, 
            {Keys::DOWN, 0.0f}, 
            {Keys::RIGHT, 1.0f}
        };
        //posizione sulla mappa (linea)
        int position;
        //velocità del player (costante)
        float speed;
        //true se il player è in movimento
        bool isMoving;
        //numero di iterazioni necessarie a completare il movimento
        unsigned counter;
        //attuale direzione di movimento
        Keys dir;
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

        void set_dir(Keys);

        void move();

        void print();
};

#endif