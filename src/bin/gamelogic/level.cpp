#include"../../include/gamelogic/level.hpp"

Collision Level::player_collides() {

    return player_line()->collides(player);
}

bool Level::player_in_area() {

    return 
        in_range<float>(-0.5f, player.next_pos(), float(lines.size()-1), true, false) 
    and
        in_range<float>(0.0f, player.next_coord(), Graphics::getInstance().get_line_width()-player.get_length(), true, false);
}

Line* Level::player_line() {

    return lines.at(player.get_position());
}

void Level::update_game_state() {

    //std::cout << "\nLevel::update_game_state() called... \n";

    switch(player_collides()) {

        case Collision::Deadly:
            player.lose_life(); 
            if(player.is_dead()) exit = true;
            else                 player.reposition();            
            break;
        
        case Collision::Arrival:
            ++frogs_counter;
            if(frogs_counter >= 5)
                exit = true;
            break;
        
        case Collision::Log:
            player.reposition(player.get_position(), player.get_coord() + player_line()->get_speed());
            break;

        default:
            //std::cout << "UNHANDLED OR NO COLLISION\n";
            break;
    }

    if(!player.is_dead()) {
        if(!player.is_moving()) {
        
            Keys temp = EventHandler::getInstance().next_key();

            if(temp != Keys::nd)
                player.set_dir(temp);
        
            if(player_in_area()) player.update();
            else                 player.set_still();   
        
        } else 
            player.update();
    }

    for(auto& it : lines)
        it->update();
}

void Level::reset_game_state() {

    //std::cout << "Level::reset_game_state()... \n";
    exit = false;
    pause = false;
    frogs_counter = 0;
    player.reset();
    for(auto& it : lines)
        it->reset();
}

void Level::redraw_game() {

    //std::cout << "Level::redraw_game() called... \n";
    for(auto& it : lines)
        it->redraw();
    player.redraw();
    Graphics::getInstance().schedule_text("TIME:",  620, 20,  al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text("SCORE:", 620, 120, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text("LIFES:", 620, 220, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text("SAVED:", 620, 320, al_map_rgb(255, 255, 255));
    Graphics::getInstance().redraw();
}

PanelType Level::type() {

    return PanelType::LEVEL;
}

PanelType Level::body(PanelType caller) {

    std::cout << "\nLevel::body() called... \n";

    reset_game_state();

    EventHandler& evh = EventHandler::getInstance();
    evh.launch();

    while(!exit) {

        Event e = evh.next_event();
        switch(e) {
            
            case Event::Exit:          
                //std::cout << "EXIT EVENT\n"; 
                exit = true;    
                break;
            
            case Event::Pause:  
                //std::cout << "PAUSE EVENT\n";
                pause = !pause; 
                break;

            case Event::Execute: 
                //std::cout << "EXECUTE EVENT\n";
                if(!pause) update_game_state();
                break;

            case Event::Redraw:
                //std::cout << "REDRAW EVENT\n";
                if(!pause) redraw_game();
                break;

            default:
                //std::cout << "UNHANDLED EVENT\n";
                break;
        }
    }

    evh.suspend();

    if(player.get_lifes() == 0) return PanelType::LOSS;
    else if(frogs_counter >= 5) return PanelType::WIN;

    return PanelType::EXIT;
}

Level::Level(): 
Panel(), exit(false), pause(false), player(), lines(), frogs_counter(0) {

    std::cout << "\nLevel initialization... ";

    //std::cout << "  \ngraphics setup";
    Graphics::getInstance().set_component(this->type());
    EventHandler::getInstance();
    auto& context = Graphics::getInstance().get_initializer();

    //std::cout << "  \nplayer graphics";
    player.set_img(context[1]);
    //std::cout << "  \nlines graphics";
    for(int i = 0; i < 11; ++i)
        lines.push_back(new Line(context[i+2], i));

    std::cout << "Level initialization done.\n";
}

Level::~Level() {

    for(auto& it : lines)
        delete it;
}