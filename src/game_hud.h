/** game_hud.h
 * 
 * 
 */

#ifndef GAME_HUD_H
#define GAME_HUD_H

#include <string>
#include <vector>

#include "game_hud_element.h"

class Game_HUD{

public:

    Game_HUD(){};
    ~Game_HUD(){};  

    void update_elements();

    void add_element(Game_HUD_Element* element){ _elements.push_back(element); }

    std::vector<Game_HUD_Element*> elements(){ return _elements; }

private:

    std::vector<Game_HUD_Element*> _elements;

};

#endif