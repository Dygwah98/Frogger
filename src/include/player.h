#ifndef PLAYER_H
#define PLAYER_H

#include"gameobject.h"

class Player: public GameObject {

    private:

        inline static map<Keys, float> dpos = {
            {Keys::nd, 0.0f},
            {Keys::UP, -1.0f},
            {Keys::LEFT, 0.0f},
            {Keys::DOWN, +1.0f},
            {Keys::RIGHT, 0.0f}
        };

        inline static map<Keys, float> dcord = {
            {Keys::nd, 0.0f},
            {Keys::UP, 0.0f}, 
            {Keys::LEFT, -60.0f}, 
            {Keys::DOWN, 0.0f}, 
            {Keys::RIGHT, 60.0f}
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
        
        Player(int, float, float);
        
        Player& operator=(const Player&);

        virtual ~Player();

        void set_speed(float s) { speed = s/60.0f; }

        void set_dir(Keys);

        void move();

        float get_position() const { return position; }

        bool is_moving() const { return isMoving; }

        bool is_dead() const { return lifes == 0; }

        void lose_life() { if(lifes > 0) --lifes; }

        void reposition(const float&, const float&);

        float next_pos() const { return position + dpos.at(dir)*speed; }

        float next_coord() const { return get_coord() + dcord.at(dir)*speed; }

        void print() {  cout << "(" << position << ", " << get_coord() << ")"; }
};

#endif