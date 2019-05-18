/** component_collision.h
 * 
 *  Two circles collide when the distance between the centers
 *  is less than or equal to the sum of their radii.
 *  
 *  Perhaps at some point the area checked should become slightly more complex than
 *  circles: ships are triangular, asteroids are polygonal, lasers perhaps are rectagonal.
 */
#ifndef COMPONENT_COLLISION_H
#define COMPONENT_COLLISION_H

#include <vector>
#include "math.h"
#include "component.h"
#include "component_physics.h"

class GameObject;

class CollisionComponent: public Component{

public:

    CollisionComponent(GameObject* owner, PhysicsComponent& physics, int update_order = 10);

    ~CollisionComponent(){};

    // Prepare object to be rendered
    void update(double delta_time) override;

    void process_input(std::vector<Game_Action_Code> actions) override;

    void set_radius(float radius){ _radius = radius; }

    float radius() const{ return _radius; }

    const Vector2d get_center() const;

    // Checks if this object collides with a given object
    bool collide(const CollisionComponent& object);

    // get the rotation angle from where an object is colliding
    float collision_angle(const CollisionComponent& object);

    // Checks if the two objects (possessing collisioncomponents) intersect
    static bool intersect(const CollisionComponent& a, const CollisionComponent& b);

    bool is_ship() const { return _is_ship; }

    void ship(){ _is_ship = true; }

 private:

    PhysicsComponent& _physics;
    float _radius;
    bool _is_ship;

};

#endif