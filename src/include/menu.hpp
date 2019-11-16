#ifndef MENU_HPP
#define MENU_HPP

#include"level.hpp"
#include"options.hpp"
#include"winlose.hpp"

//Composite root node, Mediator
class Menu : public Panel {

    private:
        std::map<PanelType, Panel> panels;

    protected:
        int type() override;
        int body() override;

    public:
        Menu();
};

#endif