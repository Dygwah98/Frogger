#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"level.h"
#include"menu.h"

class GameManager {

    private:
        Graphics& g;
        vector<GameComponent*> components;
   
    protected:

    public:
        GameManager(Graphics& g);
        bool add(GameComponent* l);
};

#endif