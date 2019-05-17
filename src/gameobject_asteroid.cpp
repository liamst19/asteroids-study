/** gameobject_asteroid.h
 * 
 * 
 */

#include <vector>
#include <algorithm>
#include "math.h"
#include "gameobject_asteroid.h"
#include "component_physics.h"
#include "game.h"

/** Constructor
 * 
 * 
 */
Asteroid::Asteroid(Game* game, Vector2d position, float direction, float rotation):
    GameObject(game),
    _physics(this, position, direction, rotation, 35.0, 35.0, 1),
    _draw(this, 2)
{

    // Set Velocities
    _physics.set_velocity(_game->rand(_rand_forward_velocity_min, _rand_forward_velocity_max));
    _physics.set_angular_velocity(_game->rand(_rand_angular_velocity_min, _rand_angular_velocity_max));

    // generate shape
    _draw.set_shape(make_shape());

    add_component(&_physics);
    add_component(&_draw);
}

/** function: update()
 * 
 * 
 */
void Asteroid::update(double delta_time){
    update_components(delta_time);
}

/** function: make_shape()
 * 
 * 
 */
std::vector<Vector2d> Asteroid::make_shape(){
    std::vector<Vector2d> shape;

    int vertices = _game->rand(_rand_vertices_min, _rand_vertices_max);

    std::vector<float> angles;
    // Fill shape with random angles
    for(int i = 0; i < vertices; ++i){
        angles.push_back(_game->rand(_rand_angles_min, _rand_angles_max));
    }

    // Sort angles into shape
    std::sort(angles.begin(), angles.end());

    float radius = _game->rand(_rand_radius_min, _rand_radius_max);
    Vector2d bounds = _game->get_bounds();
    // Draw shape from angles
    for(auto angle: angles){
        shape.push_back(Vector2d(
            radius * Math::Sin(Math::ToRadians(angle)),
            -1 * radius * Math::Cos(Math::ToRadians(angle))
        ));
    }    

    return shape;
}

/** function: draw()
 * 
 * 
 */
std::vector<Vector2d> Asteroid::draw(){
    return _draw.draw_shape(_physics.position(),
                            _physics.rotation());
}