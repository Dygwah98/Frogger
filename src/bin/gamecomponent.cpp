#include"../include/gamecomponent.h"

decltype(make_unique<map<int,int> >()) GameComponent::init_map() {

    auto it = make_unique<map<int,int> >();
    it->insert({-1, -1});
    return it;
}

unique_ptr<map<int, int> > GameComponent::exec_ret = init_map();