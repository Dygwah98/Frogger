#include"../include/gamemanager.h"

GameManager::GameManager(EventHandler& eh): graphics(eh.get_graphic_context()), events(eh), components(), root(nullptr) {

    cout << "GameManager::GameManager() " << this << endl;
}

GameManager::~GameManager() {

    cout << "GameManager::~GameManager() " << this << endl;
}

void GameManager::launchGame() {

    GameComponent::map_type temp = root->exec();
    
    while(temp != GameComponent::exit_val()) {
        
        for(auto& it : components)
         if(it->get_type() == temp) {
            temp = it->exec();
            break;
        }
    }
}