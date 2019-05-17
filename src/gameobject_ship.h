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

class Ship: public GameObject{

public:

    Ship(Game* game);

    ~Ship(){};

    std::vector<Vector2d> draw() override;

private:

    PhysicsComponent _physics_component;

};

#endif