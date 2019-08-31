#include"../include/gamemanager.h"

GameManager::GameManager(Graphics& g): g(g), components(), root(nullptr) {

    cout << "GameManager::GameManager() " << this << endl;
}

GameManager::~GameManager() {

    cout << "GameManager::~GameManager() " << this << endl;
}

bool GameManager::addAsRoot(GameComponent* c) {

    components.push_back(c);
    root = c;
    return true;
}

bool GameManager::add(GameComponent* c) {

    components.push_back(c);
    return true;
}

void GameManager::launchGame() {

    map_type temp = root->exec();
    while(temp != GameComponent::get_exit_val()) {
        
        cout << "\nHey! I worked once\n";
        
        for(auto& it : components)
         if(it->get_type() == temp) {
            temp = it->exec();
            break;
        }
    }
}