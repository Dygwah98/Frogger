#ifndef LEVEL_H
#define LEVEL_H

#include"gamecomponent.h"
#include"eventhandler.h"
#include"line.h"
#include"player.h"
/*
    rappresenta l'intera istanza (solo logica?) di un livello

    vab, quantomeno l'handle alla grafica? O viceversa
*/
class Level : public GameComponent {

    private:
        
        Graphics& graphics;
        
        EventHandler& events;
        
        vector<Line> lines;
        
        Player player;

        bool is_stopped;

        int frogs_counter;

        bool position_bound(float pos) const { return in_range<float>(0.0f, pos, (float)lines.size(), true, false); }
        bool coordinate_bound(float pos) const { return in_range<float>(0.0f, pos, Line::getLineDimension(), true, false); }
        bool player_in_area() const { return position_bound(player.next_pos()) and coordinate_bound(player.next_coord()); }

        Line& player_line() { return lines.at(player.get_position()); }
        const Line& player_line() const { return lines.at(player.get_position()); }

        Line& player_next_line() { return lines.at(player.next_pos()); }
        const Line& player_next_line() const { return lines.at(player.next_pos()); }

        float line_height() const { return graphics.get_buffer_height()/(float)lines.size(); }
        float player_gpos() const { return player.get_position() * line_height() + (line_height() - player.get_dim())/2.0f; }

        Collision player_collides() const;

        bool handle_collisions();
        void update_player();
        void update_lines();

    protected:

    public:
        
        static exec_type type() { return 1; }

        Level(EventHandler&);
        
        ~Level();
        
        virtual exec_type get_type() override { return Level::type(); }
        
        virtual exec_type exec() override;
};

#endif