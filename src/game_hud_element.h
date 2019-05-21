/** game_hud_element.h
 * 
 * 
 */

#ifndef GAME_HUD_ELEMENT_H
#define GAME_HUD_ELEMENT_H

#include <string>
#include <vector>

class Game_HUD_Element{

public:

    Game_HUD_Element(){};
    ~Game_HUD_Element(){};  

    void update(double delta_time);

    // Set message
    void set_message(std::string message){ _message = message; }

    // Get message
    std::string message(){ return _message; }

private:

    std::string _message;
    int _position_x{0}, _position_y{0};

};

#endif