#ifndef PANEL_HPP
#define PANEL_HPP

#include<utility>
#include<map>

//Composite base class
class Panel {

    protected:        
        enum struct PanelType : int {EXIT = -2, MENU = -1, OPTIONS = 0, LEVEL = 1, WIN = 2, LOSS = 3};

        virtual int type() = 0;
        virtual int body() = 0;

    public:
        virtual ~Panel() {}

        inline std::pair<int, int> execute() {

            std::pair<int, int> ret;
            ret.first  = this->type();
            ret.second = this->body();
            
            return ret;
        }
};

#endif