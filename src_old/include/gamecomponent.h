#ifndef GAMECOMP_H
#define GAMECOMP_H

#include"root.h"

class GameComponent {

    private:

        typedef map<int, int> type_table;
        typedef unique_ptr<type_table> table_ptr; 

        static table_ptr init_map();

        static table_ptr exec_ret;

        virtual int type() = 0;

    protected:

        static int at(int key) { return exec_ret->at(key); }

        GameComponent(int ret_val) {

            assert( !(contains<int, int>(*exec_ret, ret_val)) );
            
            exec_ret->insert({ret_val, ret_val});

            cout << "GameComponent::GameComponent() " << this << endl;
        }

    public:
    
        static int exit_val() { return exec_ret->at(-1); }
    
        virtual ~GameComponent() { 
            cout << "GameComponent::~GameComponent() " << this << endl;
        }

        int get_type() { return this->type(); };

        virtual int exec() = 0;
};

#endif