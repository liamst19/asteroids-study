/** component_physics.h
 * 
 * get() and set() should probably be avoided; what would make good
 * alternatives? most of the set() methods probably are unnecessary, since there
 * is update(), and something like position() would be sufficient for most get()
 * 
 */
#ifndef COMPONENT_PHYSICS_H
#define COMPONENT_PHYSICS_H

#include <vector>
#include "math.h"
#include "component.h"

class PhysicsComponent: public Component{

public:

    PhysicsComponent(GameObject* owner, int update_order = 10);

    PhysicsComponent(GameObject* owner, 
                     Vector2d position, 
                     float rotation, 
                     float angular_velocity, 
                     Vector2d velocity, 
                     int update_order);

    ~PhysicsComponent(){};

    // Update position and rotation
    void update(double delta_time) override;

    void process_input(std::vector<Game_Action_Code> actions) override;

    // Get current position
    Vector2d position() const { return _position; }

    int positionX() const { return _position.x; }

    int postionY() const { return _position.y; }

    // Set current position
    void set_position(Vector2d position){ _position = position; }

    // Set current position
    void set_position(float x, float y){ _position = Vector2d(x, y); }

    // Get rotation
    float rotation() const { return _rotation; }

    void set_rotation(float rotation){ _rotation = rotation; }

    // Get velocity
    Vector2d velocity() const { return _velocity; }

    void set_velocity(Vector2d velocity);

    // Get angular velocity
    float angular_velocity() const { return _angular_velocity; }

    void set_angular_velocity(float angular_velocity);

    // Move ------------------------------

    void thrust_forward();

    void move_backward();

    void move_clockwise();

    void move_counterclockwise();

    void bounce(float angle, Vector2d velocity);

private:

    Vector2d _position;
    float _rotation;

    Vector2d _velocity;
    float _acceleration;

    float _angular_velocity;
    float _angular_acceleration;

    float _mass; // for when we can calculate more realistically, e.g. force for collision, etc.

    void update_rotation(double delta_time);
    void update_position(double delta_time);

    // Constants ------------------------------
    const float _increment_velocity{1.0};
    const float _increment_angular_velocity{5.0};
    const float _increment_rotation{1.0};

    const float _max_angular_velocity{50.0};
    const float _min_angular_velocity{0.0};
    const float _max_velocity{250.0};
    const float _min_velocity{0.0};

    static bool near_zero(Vector2d velocity){
        return !Math::NearZero(velocity.x) || !Math::NearZero(velocity.y);
    };

    float get_bounce_angle(float angle);

};

#endif