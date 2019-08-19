#include"gameobject.h"

class Player: public GameObject {

    private:
        //true se il player è vivo
        bool isAlive;
        //true se il player è in movimento
        bool isMoving;

    protected:
    
    public:
        Player(const int&, const float&);
};