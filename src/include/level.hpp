#ifndef LEVEL_HPP
#define LEVEL_HPP

#include"panel.hpp"

class Level : public Panel {

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        Level();
};

#endif