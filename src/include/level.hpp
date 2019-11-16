#ifndef LEVEL_HPP
#define LEVEL_HPP

#include"panel.hpp"

class Level : public Panel {

    protected:
        int type() override;
        int body() override;
};

#endif