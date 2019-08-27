#include"../include/player.h"

Player::Player(): GameObject(), isAlive(true), isMoving(false) {

    cout << "Player::Player() " << this << endl;
}

Player::Player(const int& i, const float& f): GameObject(i, f), isAlive(true), isMoving(false) {}

Player::~Player() {

    cout << "Player::~Player() " << this << endl;
}