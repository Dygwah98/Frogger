#include"../../include/allegro_wrappers/graphics.hpp"

Graphics* Graphics::instance = nullptr;

Graphics* Graphics::getInstance() {

    if(Graphics::instance == nullptr) {

        assert(initAllegro());
        Graphics::instance = new Graphics();
    }
    return Graphics::instance;
}

void Graphics::delInstance() {
    
    if(Graphics::instance != nullptr)
        delete Graphics::instance;
    Graphics::instance = nullptr;
}

bool Graphics::isValid = false;

bool Graphics::initAllegro() {

    if(!isValid) {
        isValid = 
            al_init() and 
            al_install_keyboard();
    }

    return isValid;
}

ALLEGRO_DISPLAY_MODE Graphics::getDispMode() const {

    ALLEGRO_DISPLAY_MODE temp;
    al_get_display_mode(0, &temp);

    for(int i = 1; i < al_get_num_display_modes(); ++i) {
        
        al_get_display_mode(i, &temp);
        if(in_range<int>(750, temp.width, 850) and in_range<int>(550, temp.height, 650))
            return temp;
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

    std::cout << "\nGraphics initialization... ";
    
    buffer.init(0.0f, 0.0f, true, true);    
    buffer.set_bitmap(800, 600);

    //inizializzazione display:
    ALLEGRO_DISPLAY_MODE data = getDispMode();

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_new_display_refresh_rate(data.refresh_rate);

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

/*
void Graphics::push_permanent_image(int element, float x, float y) {

    assert(in_range<int>(0, element, bitmaps[row].size(), true, false));
    queue.push_back( {bitmaps[row][element], x, y, true, false} );
}

//genera automaticamente due bitmap, corrispondenti alle due porzioni
//dell'immagine originale, per simulare uno shift "circolare"    
void Graphics::push_shifted_image(int element, float x, float y, float offset) {

    ALLEGRO_BITMAP* pic = bitmaps[row][element];
    float picH = al_get_bitmap_height(pic);
    float picW = al_get_bitmap_width(pic);
    
    ALLEGRO_BITMAP* left = al_create_sub_bitmap(pic, 0, 0, offset, picH);
    queue.push_back({left, x + (picW - offset), y, false, true});

    ALLEGRO_BITMAP* right = al_create_sub_bitmap(pic, offset, 0, picW - offset, picH);
    queue.push_back({right, x, y, false, true});
}
*/

void Graphics::redraw() {

    //buffer.update_buffer();
    
    //operazioni di disegno sul display
    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    buffer.draw();
    al_flip_display();

    //buffer.refresh();
}

std::vector<ALLEGRO_BITMAP*>& Graphics::get_initializer() {

    return buffer.get_initializer();
}