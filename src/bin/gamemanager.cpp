#include"../include/gamemanager.h"

GameManager::GameManager(EventHandler& eh): graphics(eh.get_graphic_context()), events(eh), components(), root(nullptr) {

    cout << "GameManager::GameManager() " << this << endl;
}

GameManager::~GameManager() {

    cout << "GameManager::~GameManager() " << this << endl;
}

void GameManager::launchGame() {

    assert(root != nullptr);
    
    GameComponent::exec_type temp = root->exec();
    
    cout << "GameManager::launchGame() " << this << endl;

    while(temp != GameComponent::exit_val()) {
        
        for(auto& it : components)
         if(it->get_type() == temp) {
            temp = it->exec();
            break;
        }
    }
}