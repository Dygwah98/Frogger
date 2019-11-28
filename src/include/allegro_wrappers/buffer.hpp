#ifndef BUFFER_HPP
#define BUFFER_HPP

#include"animatedimage.hpp"
#include"lineimage.hpp"

class Graphics;
class Buffer : public Image {

    friend class Graphics;
    private:
        PanelType row = PanelType::EXIT;
        //per ogni GameComponent, contiene le immagini che compongono backgrounds e simili
        std::map<PanelType, std::vector<ALLEGRO_BITMAP*> > bitmaps = {};
        //coda di immagini da disegnare sul buffer
        std::vector<Image*> queue = {};
        //fattori di scala (usati per ridimensionare il buffer)
        float scale[4] = {0.0f, 0.0f, 0.0f, 0.0f};

        float line_dim = 520.0f;
    
    public:
        Buffer();
        Buffer(ALLEGRO_BITMAP*, float, float, bool, bool);
        ~Buffer() override;
        
        void init(float, float, bool, bool);

        void draw() override;

        void update_buffer();

        void refresh();

        void push_image(Image* img) { queue.push_back(img); }

        std::vector<ALLEGRO_BITMAP*>& get_initializer() { return bitmaps.at(row); }

        void set_component(PanelType index);
        void clear();

        float get_line_width() const { return line_dim; };

};

#endif