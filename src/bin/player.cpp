#include"../include/player.h"

Player::Player(): GameObject(), position(0), isMoving(false), lifes(3) {

    cout << "Player::Player() " << this << endl;
}

Player::Player(const int& i, const float& f): GameObject(f), position(0), isMoving(false), lifes(3) {}

Player::~Player() {

    cout << "Player::~Player() " << this << endl;
}

int Player::get_position() const {

    return position;
}

bool Player::is_moving() const {

    return isMoving;
}