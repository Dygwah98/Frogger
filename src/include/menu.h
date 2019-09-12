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
    
        Menu(EventHandler&);
    
        ~Menu();
    
        static exec_type type() { return GameComponent::types[1]; }
    
        virtual exec_type get_type() override { return Menu::type(); }
    
        virtual exec_type exec() override;
};

#endif