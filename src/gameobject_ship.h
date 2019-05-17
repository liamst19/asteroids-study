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
#include "component_physics.h"
#include "component_input.h"
#include "component_draw.h"

class Ship: public GameObject{

public:

    Ship(Game* game, Vector2d position);

    ~Ship(){};

    std::vector<Vector2d> draw() override;

    void update(double delta_time);

private:

    PhysicsComponent    _physics;
    InputComponent      _input;
    DrawComponent       _draw;

    std::vector<Vector2d> make_shape();

};

#endif