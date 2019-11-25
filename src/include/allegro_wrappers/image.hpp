#ifndef IMAGE_HPP
#define IMAGE_HPP

#include"../root.hpp"

class Image {

    private:
        bool permanent;
        bool deletable;

    protected:
        ALLEGRO_BITMAP* bitmap;
        float x;
        float y;

    public:
        Image();
        Image(ALLEGRO_BITMAP*, float, float, bool, bool);
        Image(const Image&);
        Image& operator=(const Image&);
        virtual ~Image();

        virtual void draw();

        bool is_permanent() const;
        bool needs_freeing() const;
        float get_x() const;
        float get_y() const;

        void set_bitmap(int, int);
        void set_bitmap(std::string&&);
        void set_permanent(bool);
        void set_deletable(bool);
        void set_coordinates(float, float);
        void set_x(float);
        void set_y(float);
};

class LineImage: public Image {
    
    private:
        std::vector<Image*> subImages;

    protected:

    public:
        LineImage();
        LineImage(ALLEGRO_BITMAP*, float, float, bool, bool);
        LineImage(const LineImage&);
        LineImage& operator=(const LineImage&);
        ~LineImage() override;

        void draw() override;
        void add(Image*);
};

class AnimatedImage: public Image {

    private:
        std::map<int, Image*> components;
        int actual;

    protected:

    public:
        AnimatedImage();
        AnimatedImage(ALLEGRO_BITMAP*, float, float, bool, bool);
        AnimatedImage(const AnimatedImage&);
        AnimatedImage& operator=(const AnimatedImage&);
        ~AnimatedImage() override;

        void draw() override;
        void add(int, Image*);

        void reset_gindex();
        void update_gindex();
        int get_gindex() const;
};

class Graphics;
class Buffer : public Image {

    friend class Graphics;
    private:
        PanelType row = PanelType::EXIT;
        //per ogni GameComponent, contiene le immagini che compongono backgrounds e simili
        std::map<PanelType, std::vector<ALLEGRO_BITMAP*> > bitmaps;
        //coda di immagini da disegnare sul buffer
        std::vector<Image*> queue;
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

        void set_component(PanelType index);
        //aggiunge una bitmap alla queue prendendola da backgrounds
        void push_image(Image*);
        //elimina tutti gli elementi nella queue e (al momento) NON resetta il buffer
        void clear() { queue.clear(); }

        float get_line_width() const { return line_dim; };

};

#endif