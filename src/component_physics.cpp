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
                                   float rotation,
                                   float angular_velocity,
                                   float velocity,
                                   int update_order):
    Component(owner, update_order),
    _position(position),
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
        // _rotation += angle;
        rotate_shape(angle);
    }
}

/** function: update_position()
 * 
 * 
 */
void PhysicsComponent::update_position(double delta_time){

    // Update position
    if(!Math::NearZero(_velocity)){
        _position += Vector2d::GetForward(_rotation) * (_velocity * delta_time);
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
void PhysicsComponent::set_angular_velocity(float velocity){
    _angular_velocity = velocity;

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
void PhysicsComponent::set_velocity(float velocity){
    _velocity = velocity;

    // Caps
    if(_velocity > _max_velocity){
        _velocity = _max_velocity;
    } else if(_velocity < _min_velocity){
        _velocity = _min_velocity;
    }
}

/** function: move_forward()
 * 
 * 
 */
void PhysicsComponent::move_forward(){
    // use acceleration?
    set_velocity(_velocity + _increment_velocity);
}

/** function: move_backward()
 * 
 * 
 */
void PhysicsComponent::move_backward(){
    // use acceleration (negatively)?
    set_velocity(_velocity - _increment_velocity);
}

/** function: move_clockwise()
 * 
 * 
 */
void PhysicsComponent::move_clockwise(){
    // set_angular_velocity(_angular_velocity + _increment_angular_velocity);
    _rotation += _increment_rotation;
}

/** function: move_counterclockwise()
 * 
 * 
 */
void PhysicsComponent::move_counterclockwise(){
    // set_angular_velocity(_angular_velocity - _increment_angular_velocity);
    _rotation -= _increment_rotation;
}

/** function: set_radius()
 * 
 * 
 */
void PhysicsComponent::set_radius(float radius){
    _radius = radius;
}

/** function: clear_shape()
 * 
 * 
 */
void PhysicsComponent::clear_shape(){
    if(!_shape_angles.empty()){
        _shape_angles.clear();
    }
}

/** function: add_shape_angle()
 * 
 * 
 */
void PhysicsComponent::add_shape_angle(float angle){
    _shape_angles.push_back(angle);

}

/** function: rotate_shape_angles()
 * 
 * 
 */
void PhysicsComponent::rotate_shape(float angle){
    for(std::vector<float>::iterator a = _shape_angles.begin(); a != _shape_angles.end(); ++a){
        *a += angle;
    }
}

/** function: draw_shape()
 * 
 * 
 */
std::vector<Vector2d> PhysicsComponent::draw_shape(){
    // Sort angles into shape
    std::sort(_shape_angles.begin(), _shape_angles.end());

    std::vector<Vector2d> shape;
    // Create array of Vector2d
    for(std::vector<float>::iterator angle = _shape_angles.begin(); angle != _shape_angles.end(); ++angle){
        shape.push_back(Vector2d(
            _position.x + _radius * Math::Sin(Math::ToRadians(*angle)), 
            _position.y - _radius * Math::Cos(Math::ToRadians(*angle))));
    }

    return shape;
}