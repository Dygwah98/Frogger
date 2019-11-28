#ifndef LEVEL_HPP
#define LEVEL_HPP

#include"../gui/panel.hpp"
#include"player.h"
#include"line.hpp"

class Level : public Panel {

    private:
        bool exit;
        bool pause;

        unsigned max_frogs;
        float line_speed;
        unsigned player_lifes;

        Player player;
        std::vector<Line*> lines;
        unsigned frogs_counter;

        Collision player_collides();
        bool player_in_area();
        Line* player_line();

        std::string score_calc() {
            return std::to_string(frogs_counter*500);   
        }

        void update_game_state();
        void reset_game_state();

        void redraw_game();

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        enum struct Difficulty: int {EASY=0, NORMAL=1, HARD=2};
        Level();  
        ~Level() override;

        void set_difficulty_to(Difficulty);
};

#endif