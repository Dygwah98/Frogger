#ifndef PANEL_HPP
#define PANEL_HPP

#include<utility>
#include<map>
#include"eventhandler.hpp"
#include"graphics.hpp"

//Composite base class
class Panel {

    protected:        
        enum struct PanelType : int {EXIT = -1, MENU = 0, LEVEL = 1, OPTIONS = 2, WIN = 3, LOSS = 4};

        virtual PanelType type() = 0;
        virtual PanelType body(PanelType) = 0;

    public:
        virtual ~Panel() {}

        inline PanelType execute(PanelType caller) {

            return this->body(caller);
        }
};

#endif