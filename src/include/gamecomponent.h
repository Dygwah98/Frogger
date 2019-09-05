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
        
        using map_type = char;

        virtual ~GameComponent() { 
            cout << "GameComponent::~GameComponent() " << this << endl;
        }

        virtual map_type exec()     = 0;
        
        virtual map_type get_type() = 0;

        static map_type exit_val() {
            return types[0];
        }

};

#endif