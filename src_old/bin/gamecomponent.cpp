#include"../include/gamecomponent.h"

GameComponent::table_ptr GameComponent::init_map() {

    table_ptr it = make_unique<map<int, int> >();
    it->insert({-1, -1});
    return it;
}

GameComponent::table_ptr GameComponent::exec_ret = init_map();