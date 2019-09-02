#include"../include/graphics.h"

bool Graphics::isValid = false;

bool Graphics::initAllegro() {

    isValid = al_init() and al_install_keyboard();

    return isValid;
}

ALLEGRO_DISPLAY_MODE Graphics::getDispMode() {

    cout << "Graphics::getDispMode() " << this << endl;

    ALLEGRO_DISPLAY_MODE temp;
    al_get_display_mode(0, &temp);

    for(int i = 1; i < al_get_num_display_modes(); ++i) {
        
        al_get_display_mode(i, &temp);
        if(in_range<int>(750, temp.width, 850) and in_range<int>(550, temp.height, 650))
            return temp;
    }

    return temp;
}

ALLEGRO_DISPLAY* Graphics::get_display() {

    return display;
}

Graphics::Graphics(): display(nullptr) {

    //inizializzazione dell'API di Allegro
    if(!isValid) assert(initAllegro());
    
    ALLEGRO_DISPLAY_MODE data = getDispMode();

//    cout << disp.format << " " << disp.height << " " << disp.refresh_rate << " " << disp.width << endl;

    //inizializzazione display:
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_new_display_refresh_rate(data.refresh_rate);

    display = al_create_display(data.width, data.height);
    assert(display != nullptr);

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    cout << "Graphics::Graphics() " << this << endl;
}

Graphics::~Graphics() {
    
    if(display     != nullptr) al_destroy_display(display);

    cout << "Graphics::~Graphics() " << this << endl;
}