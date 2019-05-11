/** gameobject_ship.h
 * 
 * 
 */

#ifndef GAMEOBJECT_SHIP_H
#define GAMEOBJECT_SHIP_H

#include "gameobject.h"

class Ship: public GameObject{

public:

    Ship(Game* game);

    ~Ship(){};

};

#endif