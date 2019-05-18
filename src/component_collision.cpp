/** component_collision.cpp
 * 
 * 
 */
#include <iostream>
#include <math.h>
#include <vector>
#include "component_collision.h"
#include "component_physics.h"
#include "gameobject.h"


/** Constructor
 *
 * 
 */
CollisionComponent::CollisionComponent(GameObject* owner, PhysicsComponent& physics, int update_order):
    Component(owner, update_order),
    _physics(physics),
    _is_ship(false),
    _radius(0)
{

}

/** function update()
 * 
 * 
 */
void CollisionComponent::update(double delta_time){

    for(auto obj: _owner->game_objects()){
        CollisionComponent& colliding_obj = obj->collision_component();

        if(!_is_ship && !colliding_obj.is_ship()
        && CollisionComponent::intersect(obj->collision_component(), *this)){
            // two asteroids colliding 

            float bounce_angle{collision_angle(obj->collision_component())};
            Vector2d bounce_velocity{obj->velocity()};

            if(isnan(bounce_angle)){
                bounce_angle = _owner->rotation() * -1;
                // bounce_velocity += _owner->velocity();
            }

            _physics.bounce(bounce_angle, bounce_velocity);

        } else if(_is_ship && CollisionComponent::intersect(obj->collision_component(), *this)){
            // ship colliding with asteroid
            if(_owner->state() == GameObject::GameObject_State_Code::active){
                _owner->destroy();
            }
        }
    }
}

/** function process_input()
 * 
 * 
 */
void CollisionComponent::process_input(std::vector<Game_Action_Code> actions){

}

const Vector2d CollisionComponent::get_center() const { 
    return _owner->position(); 
}

/** function: collide()
 * 
 * 
 */
bool CollisionComponent::collide(const CollisionComponent& object){
    return intersect(*this, object);
}

/** function:: collision_angle()
 * 
 *  Returns angle in degrees.
 */
float CollisionComponent::collision_angle(const CollisionComponent& object){

    Vector2d center_a = get_center();
    Vector2d center_b = object.get_center();

    float dot = Vector2d::Dot(Vector2d::Normalize(center_a), Vector2d::Normalize(center_b)); 
    float acos = Math::Acos(dot);
    float angle = Math::ToDegrees(acos);

    return angle;
}

/** function: intersect()
 * 
 * 
 */
bool CollisionComponent::intersect(const CollisionComponent& a, const CollisionComponent& b){
    Vector2d aCenter = a.get_center();
    Vector2d bCenter = b.get_center();

    if(aCenter.x == bCenter.x && aCenter.y == bCenter.y){
        return false;
    }

    // Calculate the square of distance between two circles
    Vector2d difference = aCenter - bCenter;
    float distance_sq = difference.lengthSq();

    // Calculate the sum of radii, squared
    float sum_radii = a.radius() + b.radius();
    float sum_radii_sq = sum_radii * sum_radii; // square

    return distance_sq <= sum_radii_sq;
}
