#include"../include/gamemanager.h"

GameManager::GameManager(Graphics& g): g(g), components() {

    cout << "GameManager::GameManager() " << this << endl;
}

GameManager::~GameManager() {

    cout << "GameManager::~GameManager() " << this << endl;
}

bool GameManager::add(GameComponent* c) {

    components.push_back(c);
    return true;
}