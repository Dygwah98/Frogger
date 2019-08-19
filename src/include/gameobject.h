#include"root.h"

class GameObject {

    private:
        //posizione nella mappa (ogni linea ha un suo indice)
        int line;
        //posizione nella linea (valore float -> pixel)
        float position;

    protected:
    
    public:
        GameObject(const int&, const float&);
        bool collides(const GameObject&) const;
        virtual ~GameObject();
};