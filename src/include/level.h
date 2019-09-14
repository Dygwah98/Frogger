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
        
        map<int, Line> lines;
        
        Player player;

        bool is_stopped;

        bool position_bound(float pos) const { return in_range<int>(0, pos, lines.size(), true, false); }
        bool coordinate_bound(float pos) const { return in_range<float>(0, pos, Line::getLineDimension()-pos); }

        bool player_in_area() const { return position_bound(player.next_pos()) and coordinate_bound(player.next_coord()); }

        Collision player_collides() const;

        bool handle_collisions();
        void update_player();
        void update_lines();

    protected:

    public:
        
        static exec_type type() { return 'L'; }

        Level(EventHandler&);
        
        ~Level();
        
        virtual exec_type get_type() override { return Level::type(); }
        
        virtual exec_type exec() override;
};

#endif