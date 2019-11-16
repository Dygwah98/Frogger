#ifndef MENU_HPP
#define MENU_HPP

#include"level.hpp"
#include"options.hpp"
#include"winlose.hpp"

//Composite root node, Mediator
class Menu : protected Panel {

    private:
        std::map<PanelType, Panel*> panels;

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