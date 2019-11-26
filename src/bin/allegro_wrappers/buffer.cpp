#include"../../include/allegro_wrappers/buffer.hpp"

Buffer::Buffer(): Image(), bitmaps(), queue() {

}

Buffer::Buffer(ALLEGRO_BITMAP* b, float x, float y, bool p, bool d):
    Image(b, x, y, p, d) {

}

Buffer::~Buffer() {

    for(auto vec : bitmaps)
        for(auto el : vec.second)
            al_destroy_bitmap(el);
}

void Buffer::init(float x, float y, bool p, bool d) {

    bitmaps.insert( {PanelType::LEVEL,   {} } );
    bitmaps.insert( {PanelType::MENU,    {} } );
    bitmaps.insert( {PanelType::OPTIONS, {} } );
    bitmaps.insert( {PanelType::WIN,     {} } );
    bitmaps.insert( {PanelType::LOSS,    {} } );

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][0]);
    al_clear_to_color(al_map_rgb(175, 175, 175));

    Image::set_bitmap(bitmaps[PanelType::LEVEL][0]);

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(30, 30));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][1]);
    al_clear_to_color(al_map_rgb(255, 255, 255));

//LINES TEMPORANEE
    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][2]);
    al_clear_to_color(al_map_rgb(150, 150, 150));
//
    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][3]);
    al_clear_to_color(al_map_rgb(125, 175, 255));
    al_put_pixel(line_dim/2, 300/11+1, al_map_rgb(255, 255, 255));

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][4]);
    al_clear_to_color(al_map_rgb(125, 255, 175));
    al_put_pixel(line_dim/2+20, 300/11+1, al_map_rgb(255, 255, 255));

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][5]);
    al_clear_to_color(al_map_rgb(255, 175, 125));
    al_put_pixel(line_dim/2+40, 300/11+1, al_map_rgb(255, 255, 255));

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][6]);
    al_clear_to_color(al_map_rgb(255, 125, 175));
    al_put_pixel(line_dim/2+60, 300/11+1, al_map_rgb(255, 255, 255));
//
    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][7]);
    al_clear_to_color(al_map_rgb(150, 150, 150));
//
    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][8]);
    al_clear_to_color(al_map_rgb(125, 175, 255));
    al_put_pixel(line_dim/2, 300/11+1, al_map_rgb(255, 255, 255));

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][9]);
    al_clear_to_color(al_map_rgb(125, 255, 175));
    al_put_pixel(line_dim/2+20, 300/11+1, al_map_rgb(255, 255, 255));

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][10]);
    al_clear_to_color(al_map_rgb(255, 175, 125));
    al_put_pixel(line_dim/2+40, 300/11+1, al_map_rgb(255, 255, 255));

    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][11]);
    al_clear_to_color(al_map_rgb(255, 125, 175));
    al_put_pixel(line_dim/2+60, 300/11+1, al_map_rgb(255, 255, 255));
//
    bitmaps[PanelType::LEVEL].push_back(al_create_bitmap(line_dim, 600/11+1));
    al_set_target_bitmap(bitmaps[PanelType::LEVEL][12]);
    al_clear_to_color(al_map_rgb(150, 150, 150));

    Image::set_coordinates(x, y);
    Image::set_permanent(p);
    Image::set_deletable(d);
}

void Buffer::draw() {

    al_set_target_bitmap(bitmap);
    al_clear_to_color(al_map_rgb(125, 125, 125));
    for(const auto& it : queue)
        it->draw();

    al_set_target_backbuffer(al_get_current_display());
    al_draw_scaled_bitmap(bitmap, 0.0f, 0.0f, x, y, scale[2], scale[3], scale[0], scale[1], 0);

    //si deallocano le bitmap temporanee create ad hoc
    for(auto& it : queue)
     if(it->needs_freeing())
        delete it;

    //si eliminano dalla coda le Image non permanenti
    auto it = queue.begin();
    while(it != queue.end()) {    
        if(!(**it).is_permanent())
            it = queue.erase(it);
        else
            it = it + 1;
    }

}

void Buffer::update_buffer() {}

void Buffer::refresh() {}

void Buffer::set_component(PanelType index) {

    auto f = contains<PanelType, std::vector<ALLEGRO_BITMAP*>>;
    assert(f(bitmaps, index));
    row = index;
}

void Buffer::push_image(Image* img) {
    
    queue.push_back(img);
}