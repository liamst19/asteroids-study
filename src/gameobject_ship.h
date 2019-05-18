/** gameobject_ship.h
 * 
 * 
 */

#ifndef GAMEOBJECT_SHIP_H
#define GAMEOBJECT_SHIP_H

#include <vector>
#include "randomnumber.h"
#include "gameobject.h"
#include "math.h"
#include "component_input.h"

class Ship: public GameObject{

public:

    Ship(Game* game, Vector2d position);

    ~Ship(){};

    std::vector<Vector2d> draw() override;

    void update(double delta_time);

    void destroy() override;

    void resurrect();

private:

    InputComponent      _input;
    
    Vector2d _initial_position;

    int _deaths;

    std::vector<Vector2d> make_shape();

};

#endif