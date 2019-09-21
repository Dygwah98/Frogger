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

        //mappa quest'oggetto con la bitmap corrispondente (in Graphics)
        int graphic_index;
        //posizione sulla mappa (linea)
        float position;
        //lunghezza sulla mappa (pixel)
        float vert_dim;
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
        
        Player(int, int, float);
        
        Player& operator=(const Player&);

        virtual ~Player();

        void move();

        void set_speed(float s) { speed = s/60.0f; }

        void set_dir(Keys);

        void set_still();
        
        void set_gindex(int i) { graphic_index = i; }

        int get_gindex() const { return graphic_index; }

        float get_position() const { return position; }

        float get_dim() const { return vert_dim; }

        bool is_moving() const { return isMoving; }

        bool is_dead() const { return lifes == 0; }

        void lose_life() { if(lifes > 0) --lifes; }

        int get_lifes() const { return lifes; }

        void reposition(const float&, const float&);

        float next_pos() const { 
        
            return 
            (dir != Keys::UP and dir != Keys::DOWN) 
            ? position
            : (dir == Keys::UP) 
                ? floor(position + dpos.at(dir)*speed)
                : position + dpos.at(dir)*speed + 1.0f; 
        }

        float next_coord() const { 
            
            return 
            (dir != Keys::LEFT and dir != Keys::RIGHT)
            ? get_coord()
            : (dir == Keys::LEFT)
                ? get_coord() + dcord.at(dir)*speed
                : get_coord() + dcord.at(dir)*speed + get_length(); 
        }

        void print() {  cout << "(" << position << ", " << get_coord() << ")"; }
};

#endif