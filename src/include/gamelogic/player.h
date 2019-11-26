#ifndef PLAYER_H
#define PLAYER_H

#include"gameobject.h"

class Player: public GameObject {

    private:

        inline static std::map<Keys, float> dpos = {
            {Keys::nd,    0.0f},
            {Keys::UP,   -1.0f},
            {Keys::LEFT,  0.0f},
            {Keys::DOWN, +1.0f},
            {Keys::RIGHT, 0.0f}
        };

        inline static std::map<Keys, float> dcord = {
            {Keys::nd,     0.0f},
            {Keys::UP,     0.0f}, 
            {Keys::LEFT, -60.0f}, 
            {Keys::DOWN,   0.0f}, 
            {Keys::RIGHT, 60.0f}
        };

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

        unsigned max_counter() const;

    protected:
    
    public:        
        Player();
        ~Player();

        void update() override;
        void redraw() override;
        void reset() override;
        
        void set_img(ALLEGRO_BITMAP*);

        void set_speed(float s) { speed = s/60.0f; }
        void set_dir(Keys);
        void set_still();

        float get_position() const { return position; }
        float get_dim() const { return vert_dim; }

        bool is_moving() const { return isMoving; }
        bool is_dead() const { return lifes == 0; }

        void lose_life() { if(lifes > 0) --lifes; }
        int get_lifes() const { return lifes; }

        void reposition(const float&, const float&);
        float next_pos() const;
        float next_coord() const;
};

#endif