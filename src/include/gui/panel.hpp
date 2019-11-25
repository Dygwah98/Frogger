#ifndef PANEL_HPP
#define PANEL_HPP

#include"../allegro_wrappers/eventhandler.hpp"

//Composite base class
class Panel {

    protected:
        virtual PanelType type() = 0;
        virtual PanelType body(PanelType) = 0;

    public:
        virtual ~Panel() {}

        inline PanelType execute(PanelType caller) {

            return this->body(caller);
        }
};

#endif