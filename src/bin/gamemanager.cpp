#include"../include/gamemanager.h"

GameManager::GameManager(Graphics& g): g(g), components() {}

bool GameManager::add(GameComponent* c) {

    components.push_back(c);
    return true;
}