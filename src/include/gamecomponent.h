#ifndef GAMECOMP_H
#define GAMECOMP_H

#include"root.h"

class GameComponent {

    private:

    protected:
        
        GameComponent() { 
            cout << "GameComponent::GameComponent() " << this << endl;
        }

    public:
        
        using exec_type = char;

        static exec_type exit_val() { return '_'; }
        
        virtual ~GameComponent() { 
            cout << "GameComponent::~GameComponent() " << this << endl;
        }

        virtual exec_type exec() = 0;
        
        virtual exec_type get_type() = 0;
};

#endif