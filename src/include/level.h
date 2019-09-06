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

        bool player_collides() const;

    protected:

    public:
        
        Level(EventHandler&);
        
        ~Level();
        
        static map_type type() { return GameComponent::types[2]; }
        
        virtual map_type get_type() override { return Level::type(); }
        
        virtual map_type exec() override;
};

#endif