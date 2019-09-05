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
    
        static map_type type();
    
        virtual map_type get_type() override;
    
        virtual map_type exec() override;
};

#endif