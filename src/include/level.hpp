#ifndef LEVEL_HPP
#define LEVEL_HPP

#include"panel.hpp"
#include"player.h"

class Level : public Panel {

    private:
        bool exit;
        bool pause;

        Player player;
        unsigned frogs_counter;
        //le lines le cambio o non le cambio?

        void update_game_state();
        void reset_game_state();

        void redraw_game();

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        Level();
};

#endif