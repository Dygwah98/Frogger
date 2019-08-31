#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"level.h"
#include"menu.h"

class GameManager {

    private:
        Graphics& g;
        vector<GameComponent*> components;
        GameComponent* root;
   
    protected:

    public:
        GameManager(Graphics&);
        ~GameManager();
        bool addAsRoot(GameComponent*);
        bool add(GameComponent*);
        void launchGame();
};

#endif