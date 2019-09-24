#include"../include/player.h"

unsigned Player::max_counter() const {

    return 60*(60/graphic_context.get_refresh_rate());
}

Player::Player(Graphics& g, int ind, int i, float f): 
    GameObject(g, f, 30.0f, GameObject::null_val()), 
    graphic_index(ind), position(i), vert_dim(30.0f), speed(0.0f), 
    isMoving(false), counter(0), dir(Keys::nd), lifes(3) {

    cout << "Player::Player(int, float) " << this << endl;

    set_speed(1.0f);
}

Player& Player::operator=(const Player& P) {
    
    if(this!=&P) {
        GameObject::operator=(P);
        position = P.position;
        speed = P.speed;
        isMoving = P.isMoving;
        counter = P.counter;
        dir = P.dir;
        lifes = P.lifes;
    }
    return *this;
}

Player::~Player() {

    cout << "Player::~Player() " << this << endl;
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
}

void Player::move() {
    
    if(isMoving) {

        reposition( position + dpos.at(dir)*speed, get_coord() + dcord.at(dir)*speed );
        --counter;
        if(counter == 0)
            set_still();
    }
}

float Player::next_pos() const { 
        
    return 
    (dir != Keys::UP and dir != Keys::DOWN) 
    ? position
    : (dir == Keys::UP)
        ? floor(position + dpos.at(dir)*speed*max_counter())
        : position + dpos.at(dir)*speed*max_counter() + speed; 
}

float Player::next_coord() const { 
            
    return 
    (dir != Keys::LEFT and dir != Keys::RIGHT)
    ? get_coord()
    : (dir == Keys::LEFT)
        ? floor(get_coord() + dcord.at(dir)*speed*max_counter())
        : get_coord() + dcord.at(dir)*speed*max_counter() + get_length();
}
