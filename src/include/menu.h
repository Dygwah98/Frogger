#ifndef MENU_H
#define MENU_H

#include"graphics.h"
#include"gamecomponent.h"

class Menu : public GameComponent {

    private:
        Graphics& g;
    protected:
    public:
        Menu(Graphics& g);
        ~Menu();
};

#endif