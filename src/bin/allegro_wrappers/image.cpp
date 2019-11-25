#include"../../include/allegro_wrappers/image.hpp"

//IMAGE METHODS

Image::Image(): bitmap(nullptr) {

}

Image::Image(ALLEGRO_BITMAP*, float, float, bool, bool) {

}

Image::Image(const Image&) {

}

Image& Image::operator=(const Image&) {

}

Image::~Image() {

}

void Image::draw() {

}

bool Image::is_permanent() const { return permanent; }
bool Image::needs_freeing() const { return deletable; }
float Image::get_x() const { return x; }
float Image::get_y() const { return y; }

void Image::set_bitmap(int w, int h) {

    std::cout << "\nImage::set_bitmap(int, int) called... ";

    if(bitmap != nullptr) al_destroy_bitmap(bitmap);

    bitmap = al_create_bitmap(w, h);
    x = w;
    y = h;

    std::cout << "Image::set_bitmap(int, int) complete.\n";
}

void Image::set_bitmap(std::string&& s) {

    std::cout << "\nImage::set_bitmap(std::string&&) called... ";

    if(bitmap != nullptr) al_destroy_bitmap(bitmap);

    bitmap = al_load_bitmap(s.data());
    x = al_get_bitmap_width(bitmap);
    y = al_get_bitmap_height(bitmap);

    std::cout << "Image::set_bitmap(std::string&&) complete.\n";
}

void Image::set_permanent(bool p) { permanent = p; }
void Image::set_deletable(bool d) { deletable = d; }
void Image::set_coordinates(float nx, float ny) { x = nx; y = ny; } 
void Image::set_x(float nx) { x = nx; }
void Image::set_y(float ny) { y = ny; }

//LINE-IMAGE METHODS

LineImage::LineImage() {}
LineImage::LineImage(ALLEGRO_BITMAP*, float, float, bool, bool) {}
LineImage::LineImage(const LineImage&) {}
LineImage& LineImage::operator=(const LineImage&) {}
LineImage::~LineImage() {}

void LineImage::draw() {}
void LineImage::add(Image*) {}


//BUFFER METHODS

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

void Buffer::update_buffer() {

    
}

void Buffer::refresh() {

}

void Buffer::set_component(PanelType index) {

    auto f = contains<PanelType, std::vector<ALLEGRO_BITMAP*>>;
    assert(f(bitmaps, index));
    row = index;
}

void Buffer::push_image(Image* img) {
    
    queue.push_back(img);
}