#ifndef PANEL_HPP
#define PANEL_HPP

#include<utility>
#include<map>

//Composite base class
class Panel {

    protected:        
        enum struct PanelType : int {EXIT = -2, MENU = -1, OPTIONS = 0, LEVEL = 1, WIN = 2, LOSS = 3};

        virtual PanelType type() = 0;
        virtual PanelType body(PanelType) = 0;

    public:
        virtual ~Panel() {}

        inline PanelType execute(PanelType caller) {

            return this->body(caller);
        }
};

#endif