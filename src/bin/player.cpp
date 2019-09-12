#include"../include/player.h"

Player::Player(): 
    GameObject(), position(0.0f), speed(1.0f), isMoving(false), counter(0), dir(Keys::nd), lifes(3) {

    cout << "Player::Player() " << this << endl;
}

Player::Player(int i, float f, float f2, char m): 
    GameObject(f, f2, m), position(0.0f), speed(1.0f), isMoving(false), counter(0), dir(Keys::nd), lifes(3) {}

Player::~Player() {

    cout << "Player::~Player() " << this << endl;
}

void Player::reposition(const int& i, const float& f) {

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