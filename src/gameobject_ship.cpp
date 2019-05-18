/** gameobject_ship.h
 * 
 * 
 */
#include <SDL2/SDL.h>

#include <vector>
#include "math.h"
#include "gameobject_ship.h"

/** Constructor
 * 
 * 
 */
Ship::Ship(Game* game, Vector2d position):
    GameObject(game, position, 0, 0),
    _input(this, _physics, 1),
    _deaths(0)
{
    _initial_position = position;

    // - draw component
    _draw.set_shape(make_shape());

    // prepare collision
    _collision.ship();

    // - input component
    add_component(&_input);
    add_component(&_physics);
    add_component(&_draw);
    add_component(&_collision);

    resurrect();
}

/** function: update()
 * 
 * 
 */
void Ship::update(double delta_time){
    update_components(delta_time);

    if(_state == GameObject_State_Code::destroyed){
        _destroyed_delta += delta_time;
        if(_destroyed_delta > _resurrect_delta){
            resurrect();
        }
    }
}

/** function: destroy()
 * 
 * 
 */
void Ship::destroy(){
    _state = GameObject_State_Code::destroyed;
    _destroyed_delta = 0;
    _deaths++;
    SDL_Log("Ship is destroyed x %i", _deaths);
}

/** function: resurrect()
 * 
 * 
 */
void Ship::resurrect(){
    _state = GameObject_State_Code::active;
    _physics.set_position(_initial_position);
    _physics.set_rotation(90);
    _physics.set_direction(90);
    _physics.set_velocity(Vector2d(0, 0));
    _physics.set_angular_velocity(0);
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