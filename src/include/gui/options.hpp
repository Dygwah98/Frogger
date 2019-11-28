#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include"panel.hpp"
#include"../gamelogic/level.hpp"

class Options: public Panel {

    private:
        Level& l;
        Level::Difficulty d;

        std::vector<Image*> button_pressed;
        std::vector<Image*> button_released;
        std::vector<std::string> button_text;
        std::vector<PanelType> directions;

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;
    
    public:
        Options(Level&);
};

#endif