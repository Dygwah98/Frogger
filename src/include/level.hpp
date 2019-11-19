#ifndef LEVEL_HPP
#define LEVEL_HPP

#include"panel.hpp"

class Level : public Panel {

    private:
        bool exit;
        bool pause;

        void update_game_state();

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        Level();
};

#endif