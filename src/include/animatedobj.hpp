#ifndef ANIMATED_HPP
#define ANIMATED_HPP

#include"gameobject.h"

class AnimatedGameObject: public GameObject {

    private:
        std::vector<int> bitmaps;
        int actual;

    protected:
    public:
        AnimatedGameObject(float, float, Collision, std::vector<int>&& bitmaps);
        AnimatedGameObject(const AnimatedGameObject&);
        AnimatedGameObject& operator=(const AnimatedGameObject&);

        void reset_gindex();
        virtual void update_gindex();
        int get_gindex() const;
};

#endif