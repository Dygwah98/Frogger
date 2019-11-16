#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include"panel.hpp"

class Options: public Panel {

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        Options();
};

#endif