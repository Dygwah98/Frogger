#ifndef GAMECOMP_H
#define GAMECOMP_H

#include"root.h"

class GameComponent {

    private:

    protected:
        
        GameComponent() { 
            cout << "GameComponent::GameComponent() " << this << endl;
        }

        inline static string types = "Eml";

    public:
        
        using exec_type = char;

        virtual ~GameComponent() { 
            cout << "GameComponent::~GameComponent() " << this << endl;
        }

        virtual exec_type exec()     = 0;
        
        virtual exec_type get_type() = 0;

        static exec_type exit_val() {
            return types[0];
        }

};

#endif