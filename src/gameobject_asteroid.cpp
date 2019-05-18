/** gameobject_asteroid.h
 * 
 * 
 */

#include <vector>
#include <algorithm>
#include "math.h"
#include "game.h"
#include "gameobject_asteroid.h"
#include "component_physics.h"
#include "component_collision.h"

/** Constructor
 * 
 * 
 */
Asteroid::Asteroid(Game* game, Vector2d position, float direction, float rotation):
    GameObject(game, position, direction, rotation)
{
    // Set Velocities
    _physics.set_velocity(Vector2d(_game->rand(_rand_forward_velocity_min, _rand_forward_velocity_max),
                                   _game->rand(_rand_forward_velocity_min, _rand_forward_velocity_max)));
    _physics.set_angular_velocity(_game->rand(_rand_angular_velocity_min, _rand_angular_velocity_max));

    // generate shape
    float radius = _game->rand(_rand_radius_min, _rand_radius_max);
    _draw.set_shape(make_shape(radius));

    // prepare collision
    _collision.set_radius(radius);

    add_component(&_physics);
    add_component(&_draw);
    add_component(&_collision);
}

/** function: update()
 * 
 * 
 */
void Asteroid::update(double delta_time){
    update_components(delta_time);
}

/** function: destroy()
 * 
 * 
 */
void Asteroid::destroy(){
    _state = GameObject_State_Code::destroyed;
}

/** function: make_shape()
 * 
 * 
 */
std::vector<Vector2d> Asteroid::make_shape(float radius){
    std::vector<Vector2d> shape;

    int vertices = _game->rand(_rand_vertices_min, _rand_vertices_max);

    std::vector<float> angles;
    // Fill shape with random angles
    for(int i = 0; i < vertices; ++i){
        angles.push_back(_game->rand(_rand_angles_min, _rand_angles_max));
    }

    // Sort angles into shape
    std::sort(angles.begin(), angles.end());

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