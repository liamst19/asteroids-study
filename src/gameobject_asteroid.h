/** gameobject_asteroid.h
 * 
 * 
 */

#ifndef GAMEOBJECT_ASTEROID_H
#define GAMEOBJECT_ASTEROID_H

#include "gameobject.h"

class Asteroid: public GameObject{

public:

    Asteroid(Game* game);

    ~Asteroid(){};

};

#endif