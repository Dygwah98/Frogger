#ifndef MENU_H
#define MENU_H

#include"eventhandler.h"
#include"level.h"

class Menu : public GameComponent {

    private:
        
        static int ret_val() { return 0; };

        Graphics& graphics;
        
        EventHandler& events;
    
        virtual int type() override { return at(ret_val()); }

    protected:
    
    public:
    
        static int get_type() { return at(ret_val()); }

        Menu(EventHandler&);
    
        ~Menu();
    
        virtual int exec() override;
};

#endif