#ifndef WINLOSE_HPP
#define WINLOSE_HPP

#include"panel.hpp"

class WinScreen : public Panel {

    private:
        Image* background;

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        WinScreen();
        ~WinScreen() override;
};

class LossScreen : public Panel {

    private:
        Image* background;

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;

    public:
        LossScreen();
        ~LossScreen() override;
};

#endif