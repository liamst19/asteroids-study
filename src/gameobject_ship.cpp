/** gameobject_ship.h
 * 
 * 
 */
#include <iostream>
#include <vector>
#include "math.h"
#include "gameobject_ship.h"

/** Constructor
 * 
 */
Ship::Ship(Game* game, Vector2d position):
    GameObject(game, position, 0),
    _input(this, _physics, 1),
    _deaths(0)
{
    _initial_position = position;

    // - draw component
    _draw.set_shape_active(make_shape_active());
    _draw.set_shape_destroyed(make_shape_destroyed());

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
 */
void Ship::update(double delta_time){
    update_components(delta_time);
    _survive_delta += delta_time;

    if(_state == GameObject_State_Code::destroyed){
        _destroyed_delta += delta_time;
        if(_destroyed_delta > _inactive_delta){
            resurrect();
        }
    } else if(_state == GameObject_State_Code::resurrected){
        _resurrected_delta += delta_time;
        if(_resurrected_delta > _invincible_delta){
            _state = GameObject_State_Code::active;
        }
    }
}

/** function: destroy()
 * 
 */
void Ship::destroy(){
    _state = GameObject_State_Code::destroyed;
    _destroyed_delta = 0;
    _deaths++;
    std::cout << "Ship is destroyed (x " << _deaths << ") you survived for " << _survive_delta << " seconds." << std::endl;
}

/** function: resurrect()
 * 
 */
void Ship::resurrect(){
    _state = GameObject_State_Code::resurrected;
    _resurrected_delta = 0;
    _survive_delta = 0;
    _physics.set_position(_initial_position);
    _physics.set_rotation(90);
    _physics.set_velocity(Vector2d(0, 0));
    _physics.set_angular_velocity(0);
}

/** function: make_shape()
 * 
 */
std::vector<Vector2d> Ship::make_shape_active(){
    _radius = 10;
    float short_radius = 7;

    std::vector<Vector2d> shape{
        Vector2d(short_radius * Math::Cos(Math::ToRadians(0)),
                 _radius * -Math::Sin(Math::ToRadians(0))),
        Vector2d(_radius * Math::Cos(Math::ToRadians(150)), 
                 _radius * -Math::Sin(Math::ToRadians(150))),
        Vector2d(short_radius * Math::Cos(Math::ToRadians(150)), 
                 short_radius * -Math::Sin(Math::ToRadians(150))),
        Vector2d(short_radius * Math::Cos(Math::ToRadians(210)), 
                 short_radius * -Math::Sin(Math::ToRadians(210))),
        Vector2d(_radius * Math::Cos(Math::ToRadians(210)),      
                 _radius * -Math::Sin(Math::ToRadians(210)))
    };

    return shape;
}

/** function: draw_shape_destroyed()
 * 
 */
std::vector<Vector2d> Ship::make_shape_destroyed(){
   std::vector<Vector2d> shape{
       Vector2d(5, -3), 
       Vector2d(-5, 3), 
       Vector2d(8, -5), 
       Vector2d(-8, 5), 
       Vector2d(3, -1), 
       Vector2d(-4, 3), 
   };
   return shape;
}

/** function: draw()
 * 
 */
std::vector<Vector2d> Ship::draw(){
    return _draw.draw_shape(_physics.position(),
                            _physics.rotation());
}