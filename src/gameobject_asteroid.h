/** gameobject_asteroid.h
 * 
 * 
 */

#ifndef GAMEOBJECT_ASTEROID_H
#define GAMEOBJECT_ASTEROID_H

#include <vector>
#include "randomnumber.h"
#include "gameobject.h"
#include "math.h"

class Asteroid: public GameObject{

public:

    Asteroid(Game* game, Vector2d position, float rotation);

    ~Asteroid(){};

    void update(double delta_time);

    std::vector<Vector2d> draw() override;

    void destroy() override;

private:

    const int _rand_angles_min{1}, _rand_angles_max{360};
    const int _rand_vertices_min{5}, _rand_vertices_max{15};
    const int _rand_radius_min{5}, _rand_radius_max{50};
    const int _rand_forward_velocity_min{-50}, _rand_forward_velocity_max{50};
    const int _rand_angular_velocity_min{-50}, _rand_angular_velocity_max{50};

    // generate _shape_angles in PhysicsComponent
    std::vector<Vector2d> make_shape_active(float radius);
    std::vector<Vector2d> make_shape_destroyed(float radius);

};

#endif