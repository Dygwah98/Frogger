#ifndef WINLOSE_HPP
#define WINLOSE_HPP

#include"panel.hpp"

class WinScreen : public Panel {

    protected:
        int type() override;
        int body() override;

};

class LossScreen : public Panel {

    protected:
        int type() override;
        int body() override;
};

#endif