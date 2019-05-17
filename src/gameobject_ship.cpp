/** gameobject_ship.h
 * 
 * 
 */

#include <vector>
#include "math.h"
#include "gameobject_ship.h"

/** Constructor
 * 
 * 
 */
Ship::Ship(Game* game):
    GameObject(game),
    _physics_component(this, Vector2d(250, 250), 0.0, 5.0, 5.0, 10)
{

    // - physics component
    // - draw component
    // - input component

}

/** function: draw()
 * 
 * 
 */
std::vector<Vector2d> Ship::draw(){
    return _physics_component.draw_shape();
}