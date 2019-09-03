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

Graphics::Graphics(): display(nullptr), buffer({nullptr, 0.0f, 0.0f, true}), queue() {

    //inizializzazione dell'API di Allegro
    if(!isValid) assert(initAllegro());
    
    ALLEGRO_DISPLAY_MODE data = getDispMode();
    //inizializzazione display:
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    al_set_new_display_refresh_rate(data.refresh_rate);

    display = al_create_display(data.width, data.height);
    assert(display != nullptr);

    buffer.bitmap = al_create_bitmap(data.width, data.height);
    buffer.x = data.width;
    buffer.y = data.height;  

    int sx = data.width / data.width;
    int sy = data.height / data.height;
    int scale = std::min(sx, sy);
    
    scaleW = buffer.x * scale;
    scaleH = buffer.y * scale;
    scaleX = (data.width - scaleW) / 2;    
    scaleY = (data.width - scaleH) / 2;

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

    al_set_target_bitmap(buffer.bitmap);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for(const auto& it : queue)
        al_draw_bitmap(it.bitmap, it.x, it.y, 0);
    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(buffer.bitmap, 0, 0, buffer.x, buffer.y, scaleX, scaleY, scaleW, scaleH, 0);
    remove_if(queue.begin(), queue.end(), [&](const auto& it) -> bool { return !it.is_permanent; });
}

void Graphics::clear() {

    queue.clear();
}
