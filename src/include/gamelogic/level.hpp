#ifndef LEVEL_HPP
#define LEVEL_HPP

#include"../gui/panel.hpp"
#include"player.h"
#include"line.hpp"

class Level : public Panel {

    private:
        bool exit;
        bool pause;

        Player player;
        std::vector<Line*> lines;
        unsigned frogs_counter;

        Collision player_collides();
        bool player_in_area();
        Line* player_line();

        void update_game_state();
        void reset_game_state();

        void redraw_game();

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        Level();
        ~Level() override;
};

#endif