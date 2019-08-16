#include"../include/graphics.h"

bool Graphics::isValid = false;

bool Graphics::initAllegro() {

    isValid = al_init();

    return isValid;
}

Graphics::Graphics(): display(nullptr) {

    //inizializzazione delle routines interne
    if(!isValid) assert(initAllegro());
}

Graphics::~Graphics() {
    
    if(display != nullptr)  al_destroy_display(display);
}