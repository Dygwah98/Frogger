#ifndef MENU_H
#define MENU_H

#include"graphics.h"
#include"level.h"

class Menu : public GameComponent {

    private:
        Graphics& g;
    protected:
    public:
        Menu(Graphics& g);
        ~Menu();
        static map_type type();
        virtual map_type get_type() override;
        virtual map_type exec() override;
};

#endif