#include"../../include/gamelogic/level.hpp"

Collision Level::player_collides() {

    Collision c = player_line()->collides(player);

    if(round(player.get_position()) > 0 and round(player.get_position()) <= 4)
        if(c != Collision::Log)
            c = Collision::Deadly;

    if(player.is_moving())
        c = Collision::nd;

    return c;
}

bool Level::player_in_area() {

    return in_range<float>(-0.5f, player.next_pos(), lines.size()-0.8f, true, false) 
       and in_range<float>(0.0f, player.next_coord(), Graphics::getInstance().get_line_width()-(player.get_length()/2.0f), true, false);
}

Line* Level::player_line() {

    return lines.at(round(player.get_position()));
}

void Level::update_game_state() {

    //std::cout << "\nLevel::update_game_state() called... \n";

    switch(player_collides()) {

        case Collision::Deadly:
            //std::cout << "Collision::Deadly ";
            //std::cout << round(player.get_position()) << std::endl;
            player.lose_life(); 
            if(player.is_dead())
                exit = true;
            else {
                player.reposition();
                player.set_still();
                EventHandler::getInstance().next_key();
            }
            break;
        
        case Collision::Arrival:
            //std::cout << "Collision::Arrival\n";
            ++frogs_counter;
            if(frogs_counter >= max_frogs)
                exit = true;
            player.reposition();
            player.set_still();
            EventHandler::getInstance().next_key();
            //lines.back()->remove_nearest_to(player.get_coord());

            break;
        
        case Collision::Log:
            //std::cout << "Collision::Log ";
            //std::cout << round(player.get_position()) << std::endl;
            if(!player.is_moving()) {
                float newcord = player.get_coord() - player_line()->get_speed();
                if(newcord > 0)
                    player.reposition(player.get_position(), player.get_coord() - player_line()->get_speed());
                else {
                    player.lose_life();
                    if(player.is_dead())
                        exit = true;
                    else {
                        player.reposition();
                        player.set_still();
                        EventHandler::getInstance().next_key();
                    }
                }
            }
            
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
    player.set_lifes(player_lifes);
    for(unsigned i = 0; i < lines.size(); ++i) {
        auto it = std::next(lines.begin(), i);
        (**it).reset();
        if(i%5 != 0)
        (**it).set_speed(line_speed);
    }
}

void Level::redraw_game() {

    //std::cout << "Level::redraw_game() called... \n";
    for(auto& it : lines)
        it->redraw();
    player.redraw();
    Graphics::getInstance().schedule_text("TIME:",                                       620, 20,  al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text(EventHandler::getInstance().get_time().data(), 720, 20,  al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text("SCORE:",                                      620, 120, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text(score_calc().data(),                           720, 120, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text("LIFES:",                                      620, 220, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text(std::to_string(player.get_lifes()).data(),     720, 220, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text("SAVED:",                                      620, 320, al_map_rgb(255, 255, 255));
    Graphics::getInstance().schedule_text(std::to_string(frogs_counter).data(),          720, 320, al_map_rgb(255, 255, 255));
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

    bool forced_exit = false;
    while(!exit) {

        Event e = evh.next_event();
        switch(e) {
            
            case Event::Exit:          
                //std::cout << "EXIT EVENT\n"; 
                exit = true; 
                forced_exit = true;   
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
    
    update_game_state();
    redraw_game();
    al_rest(0.5f);

    evh.suspend();

    if(!forced_exit) {
        if(player.is_dead()) 
            return PanelType::LOSS;
        else if(frogs_counter >= max_frogs)
            return PanelType::WIN;
    }

    return PanelType::MENU;
}

Level::Level(): 
Panel(), exit(false), pause(false), player(), lines(), frogs_counter(0) {

    std::cout << "\nLevel initialization... ";

    Graphics::getInstance().set_component(this->type());
    EventHandler::getInstance();

    auto& context = Graphics::getInstance().get_initializer();

    player.set_img(context[1]);
    for(int i = 0; i < 11; ++i)
        lines.push_back(new Line(context[i+2], i));

    set_difficulty_to(Difficulty::NORMAL);

    std::cout << "Level initialization done.\n";
}

Level::~Level() {

    for(auto& it : lines)
        delete it;
}

void Level::set_difficulty_to(Difficulty d) {

    if(d == Difficulty::EASY) {

        max_frogs = 1;
        line_speed = 0.5f;
        player_lifes = 100;

    } else if(d == Difficulty::NORMAL) {

        max_frogs = 3;
        line_speed = 1.0f;
        player_lifes = 3;

    } else {

        max_frogs = 5;
        line_speed = 2.5f;
        player_lifes = 1;
    }
}