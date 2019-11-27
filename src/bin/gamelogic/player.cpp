#include"../../include/gamelogic/player.h"

unsigned Player::max_counter() const {

    unsigned int temp = Graphics::getInstance()->get_refresh_rate();
    assert(temp != 0);
    return 60*(60/temp);
}

Player::Player(): 
    GameObject(0.0f, 30.0f, Collision::nd), 
    position(0), vert_dim(30.0f), speed(1.0f), isMoving(false), counter(0), dir(Keys::nd), lifes(3) {}

Player::~Player() {}

void Player::reposition(const float& i, const float& f) {

    position = i;
    set_coord(f);
    get_img()->set_coordinates(f, ((Graphics::getInstance()->get_line_height() - get_length())/2.0f)*(position+1.0f));
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
void Player::update() {
    
    if(isMoving) {
        reposition( position + (dpos.at(dir)*speed)/max_counter(), get_coord() + dcord.at(dir)*speed );
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
        ? floor(position + dpos.at(dir) * speed)
        : position + dpos.at(dir) * speed + speed; 
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
    speed = 1.0f;
    isMoving = false;
    counter = 0;
    dir = Keys::nd;
    lifes = 3;
}

//get_gindex(), get_coord() + 5.0f, 12.27f

void Player::redraw() {

    GameObject::redraw();    
}

void Player::set_img(ALLEGRO_BITMAP* b) {

    GameObject::set_img(b);
    float temp = Graphics::getInstance()->get_line_height();
    get_img()->set_coordinates( (temp-vert_dim)/2.0f, (temp-get_length())/2.0f );
}