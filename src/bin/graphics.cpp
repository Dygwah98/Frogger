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

void Graphics::calc_scale_factors() {

    float scale = std::min(
        al_get_display_width(display)/buffer.x,
        al_get_display_height(display)/buffer.y
    );
    
    scaleW = buffer.x * scale;
    scaleH = buffer.y * scale;
    scaleX = (al_get_display_width(display) - scaleW) / 2;    
    scaleY = (al_get_display_height(display) - scaleH) / 2;

}

Graphics::Graphics(): display(nullptr), buffer({nullptr, 0.0f, 0.0f, true}), queue() {

    //inizializzazione dell'API di Allegro
    if(!isValid) assert(initAllegro());

    //inizializzazione display:
    ALLEGRO_DISPLAY_MODE data = getDispMode();

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_new_display_refresh_rate(data.refresh_rate);

    display = al_create_display(data.width, data.height);
    assert(display != nullptr);

    //inizializzazione buffer
    buffer.bitmap = al_create_bitmap(800, 600);
    buffer.x = 800;
    buffer.y = 600;  

    calc_scale_factors();

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    cout << "Graphics::Graphics() " << this << endl;
}

Graphics::~Graphics() {
    
    if(display != nullptr)
        al_destroy_display(display);
    if(buffer.bitmap != nullptr)
        al_destroy_bitmap(buffer.bitmap);

    cout << "Graphics::~Graphics() " << this << endl;
}

void Graphics::push_image(ALLEGRO_BITMAP* b, float x, float y, Priority pr, bool is_p) {
    //priority va usata per l'inserimento in coda
    queue.push_back( {b, x, y, is_p} );
}

void Graphics::redraw() {

    ALLEGRO_BITMAP* temp = al_create_bitmap(460, 600);
    al_set_target_bitmap(temp);
    al_clear_to_color(al_map_rgb(175, 175, 175));

    //operazioni di disegno sul buffer
    al_set_target_bitmap(buffer.bitmap);
    al_clear_to_color(al_map_rgb(125, 125, 125));
    al_draw_bitmap(temp, 0, 0, 0);
    for(const auto& it : queue)
        al_draw_bitmap(it.bitmap, it.x, it.y, 0);
    
    //operazioni di disegno sul display
    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //i parametri .x e .y di Image vengono utilizzati come width e height, per semplicità
    al_draw_scaled_bitmap(buffer.bitmap, 0, 0, buffer.x, buffer.y, scaleX, scaleY, scaleW, scaleH, 0);
    al_flip_display();
    
    //si eliminano dalla coda le immagini non permanenti
    auto it = queue.begin();
    while(it != queue.end()) {    
        if(!it->is_permanent)
            it = queue.erase(it);
        else
            ++it;
    }

    al_destroy_bitmap(temp);
}