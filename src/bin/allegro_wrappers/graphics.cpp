#include"../../include/allegro_wrappers/graphics.hpp"

Graphics* Graphics::instance = nullptr;

Graphics& Graphics::getInstance() {

    if(Graphics::instance == nullptr) {

        Graphics::instance = new Graphics();
    }
    return *(Graphics::instance);
}

void Graphics::delInstance() {
    
    if(Graphics::instance != nullptr)
        delete Graphics::instance;
    Graphics::instance = nullptr;
}

bool Graphics::isValid = false;

bool Graphics::initAllegro() {

    if(!isValid) {
        al_init(); 
        al_install_keyboard();
        al_init_image_addon();
    
        isValid = al_is_system_installed() and al_is_keyboard_installed();
    }

    return isValid;
}

ALLEGRO_DISPLAY_MODE Graphics::getDispMode() const {

    ALLEGRO_DISPLAY_MODE temp;
    al_get_display_mode(0, &temp);

    for(int i = 1; i < al_get_num_display_modes(); ++i) {
        
        al_get_display_mode(i, &temp);
        if(in_range<int>(750, temp.width, 850) and in_range<int>(550, temp.height, 650)) {
            return temp;
        }
    }

    return temp;
}

void Graphics::calc_scale_factors() {

    float dw = get_display_width();
    float dh = get_display_height();

    float ratio = std::min(
        dw / buffer.get_x(),
        dh / buffer.get_y()
    );
    
    buffer.scale[0] = buffer.get_x() * ratio;
    buffer.scale[1] = buffer.get_y() * ratio;
    buffer.scale[2] = (dw - buffer.scale[0]) / 2.0f;    
    buffer.scale[3] = (dh - buffer.scale[1]) / 2.0f;
}

Graphics::Graphics():
    display(nullptr), buffer() {

    assert(initAllegro());

    std::cout << "\nGraphics initialization... ";
    
    buffer.init(800, 600, false);    
    buffer.set_bitmap(800, 600);

    //inizializzazione display:
    ALLEGRO_DISPLAY_MODE data = getDispMode();

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_new_display_refresh_rate(get_refresh_rate());

    display = al_create_display(data.width, data.height);
    assert(display != nullptr);

    //inizializzazione buffer
    calc_scale_factors();
    
    std::cout << "Graphics initialization done.\n";
}

Graphics::~Graphics() {
    
    if(display != nullptr)
        al_destroy_display(display);
}

void Graphics::redraw() {
    
    buffer.update_buffer();

    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0, 0, 0));

    buffer.draw();
    al_flip_display();

    buffer.clear();
}

std::vector<ALLEGRO_BITMAP*>& Graphics::get_initializer() {

    return buffer.get_initializer();
}