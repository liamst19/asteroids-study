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
Ship::Ship(Game* game, Vector2d position):
    GameObject(game),
    _input(this, _physics, 1),
    _physics(this, position, 0, 0, 0, Vector2d(), 2),
    _draw(this, 3)
{

    // - physics component
    _physics.set_rotation(90);
    _physics.set_direction(90);

    // - draw component
    _draw.set_shape(make_shape());

    // - input component
    add_component(&_input);
    add_component(&_physics);
    add_component(&_draw);
}

/** function: update()
 * 
 * 
 */
void Ship::update(double delta_time){
    update_components(delta_time);
}


/** function: make_shape()
 * 
 * 
 */
std::vector<Vector2d> Ship::make_shape(){
    float radius = 10;
    float short_radius = 7;
    _physics.set_direction(90);
    _physics.set_rotation(90);

    std::vector<Vector2d> shape{
        Vector2d(short_radius * Math::Cos(Math::ToRadians(0)),   radius * -Math::Sin(Math::ToRadians(0))),
        Vector2d(radius * Math::Cos(Math::ToRadians(150)), radius * -Math::Sin(Math::ToRadians(150))),
        Vector2d(short_radius * Math::Cos(Math::ToRadians(150)), short_radius * -Math::Sin(Math::ToRadians(150))),
        Vector2d(short_radius * Math::Cos(Math::ToRadians(210)), short_radius * -Math::Sin(Math::ToRadians(210))),
        Vector2d(radius * Math::Cos(Math::ToRadians(210)), radius * -Math::Sin(Math::ToRadians(210)))
    };

    return shape;
}

/** function: draw()
 * 
 * 
 */
std::vector<Vector2d> Ship::draw(){
    return _draw.draw_shape(_physics.position(),
                            _physics.rotation());
}