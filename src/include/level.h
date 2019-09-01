#ifndef LEVEL_H
#define LEVEL_H

#include"gamecomponent.h"
#include"graphics.h"
#include"line.h"
#include"player.h"
/*
    rappresenta l'intera istanza (solo logica?) di un livello

    vab, quantomeno l'handle alla grafica? O viceversa
*/
class Level : public GameComponent {

    private:
        Graphics& graphics;
        map<int, Line> lines;
        Player player;

    protected:

    public:
        Level(Graphics&);
        ~Level();
        static map_type type();
        virtual map_type get_type() override;
        virtual map_type exec() override;
};

#endif