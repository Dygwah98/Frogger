#include"../../include/gamelogic/player.h"

unsigned Player::max_counter() const {

    unsigned int temp = Graphics::getInstance()->get_refresh_rate();
    assert(temp != 0);
    return 60*(60/temp);
}

Player::Player(): 
    GameObject(1.0f, 30.0f, Collision::nd), 
    position(0), vert_dim(30.0f), speed(1.0f), isMoving(false), counter(0), dir(Keys::nd), lifes(3) {

    std::cout << "Player::Player(int, int, float) " << this << std::endl;
}

Player::~Player() {

    std::cout << "Player::~Player() " << this << std::endl;
}

void Player::reposition(const float& i, const float& f) {

    position = i;
    set_coord(f);
}

void Player::set_dir(Keys key) {
    
    if(!isMoving) {
    
        isMoving = true;
        dir = key;
        counter = max_counter();
    }
}

void Player::set_still() {

    isMoving = false;
    counter = 0;
    //reset_gindex();
}
/*
void Player::update_gindex() {

    if(isMoving)
        AnimatedGameObject::update_gindex();
}
*/
void Player::move() {
    
    if(isMoving) {

        reposition( position + dpos.at(dir)*speed, get_coord() + dcord.at(dir)*speed );
        --counter;
        if(counter == 0) {
            set_still();
        } else {} 
            //update_gindex();
    }
}

float Player::next_pos() const { 
        
    return 
    (dir != Keys::UP and dir != Keys::DOWN) 
    ? position
    : (dir == Keys::UP)
        ? floor(position + dpos.at(dir) * speed * max_counter())
        : position + dpos.at(dir) * speed * max_counter() + speed; 
}

float Player::next_coord() const { 
            
    return 
    (dir != Keys::LEFT and dir != Keys::RIGHT)
    ? get_coord()
    : (dir == Keys::LEFT)
        ? floor(get_coord() + dcord.at(dir) * speed * max_counter())
        : get_coord() + dcord.at(dir) * speed * max_counter() + get_length();
}

void Player::reset() {

    //reset_gindex();
    position = 0;
    vert_dim = 30.0f;
    speed = 0.0f;
    isMoving = false;
    counter = 0;
    dir = Keys::nd;
    lifes = 3;
}

//get_gindex(), get_coord() + 5.0f, 12.27f

void Player::redraw() {
    
    //Graphics::getInstance()->push_image();
}