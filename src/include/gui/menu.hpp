#ifndef MENU_HPP
#define MENU_HPP

#include"../gamelogic/level.hpp"
#include"options.hpp"
#include"winlose.hpp"

//Composite root node, Mediator
class Menu : protected Panel {

    private:
        std::map<PanelType, Panel*> panels;

        std::vector<Image*> button_pressed;
        std::vector<Image*> button_released;
        std::vector<PanelType> directions;

        PanelType runMenuScreen();

    protected:
        PanelType type() override;
        PanelType body(PanelType) override;

    public:
        Menu();
        ~Menu();
        
        void launchGame();
};

#endif