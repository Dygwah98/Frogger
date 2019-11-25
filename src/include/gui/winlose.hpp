#ifndef WINLOSE_HPP
#define WINLOSE_HPP

#include"panel.hpp"

class WinScreen : public Panel {

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        WinScreen();

};

class LossScreen : public Panel {

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;

    public:
        LossScreen();
};

#endif