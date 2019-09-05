#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include"level.h"
#include"menu.h"

class GameManager {

    private:

        Graphics& graphics;
    
        EventHandler& events;
    
        vector<GameComponent*> components;
    
        GameComponent* root;
   
    protected:

    public:
    
        GameManager(EventHandler&);
    
        ~GameManager();
    
        bool addAsRoot(GameComponent*);
    
        bool add(GameComponent*);
    
        void launchGame();
};

#endif