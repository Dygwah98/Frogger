#include"../../include/allegro_wrappers/buffer.hpp"

Buffer::Buffer(): Image() {}

Buffer::Buffer(ALLEGRO_BITMAP* b, float x, float y, bool d):
    Image(b, x, y, d) {}

Buffer::~Buffer() {

    for(auto vec : bitmaps)
        for(auto el : vec.second)
            al_destroy_bitmap(el);
}

void Buffer::init(float x, float y, bool d, const char* data) {

    Image::set_coordinates(x, y);
    Image::set_deletable(d);

    bitmaps.insert( {PanelType::LEVEL,   {} } );
    bitmaps.insert( {PanelType::MENU,    {} } );
    bitmaps.insert( {PanelType::OPTIONS, {} } );
    bitmaps.insert( {PanelType::WIN,     {} } );
    bitmaps.insert( {PanelType::LOSS,    {} } );


    font = al_load_ttf_font(data, 24, 0);
    assert(font != nullptr);

    bitmaps[PanelType::LEVEL].push_back(al_load_bitmap("resources/Senzanome.png"));

    bitmaps[PanelType::LEVEL].push_back(
        al_create_sub_bitmap(bitmaps[PanelType::LEVEL][0], line_dim, 0, 30, 30));
    
    int h = 56;
    int arr[] = {0,   1,   2,   3,   4};

    for(int i = 0; i < 11; ++i) {
        
        bitmaps[PanelType::LEVEL].push_back(
            al_create_sub_bitmap(bitmaps[PanelType::LEVEL][0], 0, arr[i%5]*h, line_dim, h)
        );
    }

    bitmaps[PanelType::LEVEL].push_back(
        al_create_sub_bitmap(bitmaps[PanelType::LEVEL][0], line_dim+60, 0, 30, 30));

    bitmaps[PanelType::LEVEL].push_back(
        al_create_sub_bitmap(bitmaps[PanelType::LEVEL][0], line_dim+60, arr[4]*h + 10, 30, 30));
}

void Buffer::draw() { al_draw_scaled_bitmap(bitmap, 0, 0, x, y, scale[2], scale[3], scale[0], scale[1], 0); }

void Buffer::clear() {

    for(auto& it : queue)
     if(it->needs_freeing())
        delete it;

    queue.clear();
    text.clear();
}

void Buffer::update_buffer() {

    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(125, 125, 125));
    
    al_hold_bitmap_drawing(true);
    for(auto it = queue.begin(); it != queue.end(); ++it)
        (*it)->draw();
    al_hold_bitmap_drawing(false);

    for(auto& it : text) 
        al_draw_text(
            font, 
            std::get<3>(it), 
            std::get<0>(it), 
            std::get<1>(it), 
            0, 
            std::get<2>(it).data()
        );
}

void Buffer::refresh() {}

void Buffer::set_component(PanelType index) {

    auto* f = contains<PanelType, std::vector<ALLEGRO_BITMAP*>>;
    assert(f(bitmaps, index));
    row = index;
}