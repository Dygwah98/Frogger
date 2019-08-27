#ifndef GAMECOMP_H
#define GAMECOMP_H

#include"root.h"

class GameComponent {

    private:
    protected:
        GameComponent()     { cout << "GameComponent::GameComponent() " << this << endl;  }
    public:
        virtual ~GameComponent()    { cout << "GameComponent::~GameComponent() " << this << endl; }
};

#endif