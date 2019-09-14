#ifndef MENU_H
#define MENU_H

#include"eventhandler.h"
#include"level.h"

class Menu : public GameComponent {

    private:
        
        Graphics& graphics;
        
        EventHandler& events;
    
    protected:
    
    public:
    
        static exec_type type() { return 'M'; }

        Menu(EventHandler&);
    
        ~Menu();
    
        virtual exec_type get_type() override { return Menu::type(); }
    
        virtual exec_type exec() override;
};

#endif