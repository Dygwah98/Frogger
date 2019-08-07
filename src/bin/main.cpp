#include"..\include\root.h"
#include<allegro5\allegro.h>

int main(int argv, char** argc) {

    if(!al_init()) {

        std::cerr << "al_init() failed\n";
        return -1;
    }

    return 0;
}