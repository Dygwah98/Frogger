#include"../include/player.h"

Player::Player(): 
    GameObject(), position(0.0f), speed(1.0f), isMoving(false), counter(0), dir(Keys::nd), lifes(3) {

    cout << "Player::Player() " << this << endl;
}

Player::Player(const int& i, const float& f): 
    GameObject(f), position(0.0f), speed(1.0f), isMoving(false), counter(0), dir(Keys::nd), lifes(3) {}

Player::~Player() {

    cout << "Player::~Player() " << this << endl;
}

inline float Player::get_position() const {

    return position;
}

inline bool Player::is_moving() const {

    return isMoving;
}

inline bool Player::is_dead() const {

    return lifes == 0;
}

inline void Player::lose_life() {

    if(lifes > 0) --lifes;
}

inline void Player::reposition(const int& i, const float& f) {

    position = i;
    set_coord(f);
}

void Player::set_dir(Keys key) {
    
    if(!isMoving) {
    
        isMoving = true;
        dir = key;
        counter = 60;
    }
}

void Player::move() {
    
    reposition( position + dpos.at(dir)*speed, get_coord() + dcord.at(dir)*speed );
    if(isMoving) {

        --counter;
        if(counter == 0) {
            isMoving = false;
            counter = 0;
            dir = Keys::nd;
        }
    }
}

inline void Player::print() {

    cout << "(" << position << ", " << get_coord() << ")";
}