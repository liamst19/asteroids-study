/** component_physics.cpp
 * 
 * 
 */

#include <SDL2/SDL.h>

#include <algorithm>
#include "gameobject.h"
#include "component_physics.h"
#include "math.h"

/** Constructor
 * 
 * 
 */
PhysicsComponent::PhysicsComponent(GameObject* owner, int update_order):
    Component(owner, update_order){
}

/** Constructor with initial position and velocitys
 * 
 * 
 */
PhysicsComponent::PhysicsComponent(GameObject* owner,
                                   Vector2d position,
                                   float direction,
                                   float rotation,
                                   float angular_velocity,
                                   Vector2d velocity,
                                   int update_order):
    Component(owner, update_order),
    _position(position),
    _direction(direction),
    _rotation(rotation){
        // Go through methods in case they exceed min/max.
        set_velocity(velocity);
        set_angular_velocity(angular_velocity);
}

/** function update()
 * 
 * 
 */
void PhysicsComponent::update(double delta_time){
    update_rotation(delta_time);
    update_position(delta_time);
}

/** function: update_rotation()
 * 
 * 
 */
void PhysicsComponent::update_rotation(double delta_time){
    if(!Math::NearZero(_angular_velocity)){
        float angle = _angular_velocity * delta_time;
        _rotation += angle;
    }
}

/** function: update_position()
 * 
 * 
 */
void PhysicsComponent::update_position(double delta_time){

    // Update position
    if(near_zero(_velocity)){
        _position +=  _velocity * delta_time;

        Vector2d bounds = _owner->get_bounds();

        // Warp if position is beyond the bounds
        if(_position.x < 0){
            _position.x = bounds.x;
        } else if(_position.x > bounds.x){
            _position.x = 0;
        }

        if(_position.y < 0){
            _position.y = bounds.y;
        } else if(_position.y > bounds.y){
            _position.y = 0;
        }
    }
}

/** function process_input()
 * 
 * 
 */
void PhysicsComponent::process_input(Game_Action_Code action){
}

/** function: set_angular_velocity()
 * 
 * 
 */
void PhysicsComponent::set_angular_velocity(float angular_velocity){
    _angular_velocity = angular_velocity;

    // Caps
    if(_angular_velocity > _max_angular_velocity){
        _angular_velocity = _max_angular_velocity;
    } else if(_angular_velocity < _min_angular_velocity){
        _angular_velocity = _min_angular_velocity;
    }
}

/** function: set_velocity()
 * 
 * 
 */
void PhysicsComponent::set_velocity(Vector2d velocity){
    _velocity = velocity;


    // Caps
    // if(_velocity.x > _max_velocity){
    //     _velocity.x = _max_velocity;
    // }

    // if(_velocity.y > _max_velocity){
    //     _velocity.y = _max_velocity;
    // }
}

/** function: thrust_forward()
 * 
 * 
 */
void PhysicsComponent::thrust_forward(){
    // use acceleration?
    Vector2d velocity = _velocity + (_increment_velocity * Vector2d::GetForward(Math::ToRadians(_rotation)));

    if(velocity.length() > _max_velocity){
        velocity = _max_velocity * Vector2d::GetForward(Math::ToRadians(_rotation));
    }
    set_velocity(velocity);
}

/** function: move_backward()
 * 
 * 
 */
void PhysicsComponent::move_backward(){
    // use acceleration (negatively)?
    set_velocity(_velocity - _increment_velocity * Vector2d::GetForward(Math::ToRadians(_rotation)));
}

/** function: move_clockwise()
 * 
 * 
 */
void PhysicsComponent::move_clockwise(){
    _rotation  += _increment_rotation;
}

/** function: move_counterclockwise()
 * 
 * 
 */
void PhysicsComponent::move_counterclockwise(){
    _rotation  -= _increment_rotation;
}