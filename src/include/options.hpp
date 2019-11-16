#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include"panel.hpp"

class Options: public Panel {

    protected:
        int type() override;
        int body() override;
};

#endif