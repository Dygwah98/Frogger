#ifndef GAMECOMP_H
#define GAMECOMP_H

#include"root.h"

typedef char map_type;

class GameComponent {

    private:
        inline static map<map_type, int> map = {
            {'E', -1}, {'m', 0}, {'l', 1}
        };
        
    protected:
        GameComponent() { 
            cout << "GameComponent::GameComponent() " << this << endl;
        }

    public:
        virtual ~GameComponent() { 
            cout << "GameComponent::~GameComponent() " << this << endl;
        }

        virtual map_type exec()     = 0;
        virtual map_type get_type() = 0;

        static map_type get_exit_key() {
            return 'E';
        }
};

#endif