#ifndef GAMECOMP_H
#define GAMECOMP_H

#include"root.h"

class GameComponent {

    private:

        static decltype(make_unique<map<int,int> >()) init_map();

        static unique_ptr<map<int, int> > exec_ret;

        virtual int type() = 0;

    protected:

        static int at(int key) { return exec_ret->at(key); }

        GameComponent(int ret_val) {

            assert( !(contains<int, int>(*exec_ret, ret_val)) );
            
            (*exec_ret)[ret_val] = ret_val;

            cout << "GameComponent::GameComponent() " << this << endl;
        }

    public:
    
        static int exit_val() { return exec_ret->at(-1); }
    
        int get_type() { return this->type(); };

        virtual ~GameComponent() { 
            cout << "GameComponent::~GameComponent() " << this << endl;
        }

        virtual int exec() = 0;
};

#endif