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
        float position;
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

        float get_position() const { return position; }

        bool is_moving() const { return isMoving; }

        bool is_dead() const { return lifes == 0; }

        void lose_life() { if(lifes > 0) --lifes; }

        void reposition(const int&, const float&);

        void set_dir(Keys);

        float next_pos() const { return position + dpos.at(dir)*speed; }

        float next_coord() const { return get_coord() + dcord.at(dir)*speed; }

        void move();

        void print() {  cout << "(" << position << ", " << get_coord() << ")"; }
};

#endif