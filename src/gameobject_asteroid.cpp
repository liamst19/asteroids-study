/** gameobject_asteroid.h
 * 
 * 
 */

#include <algorithm>
#include "math.h"
#include "gameobject_asteroid.h"
#include "component_physics.h"
#include "game.h"

/** Constructor
 * 
 * 
 */
Asteroid::Asteroid(Game* game, Vector2d position, float rotation):
    GameObject(game),
    _physics_component(this, position, rotation, 35.0, 35.0, 10)
{
    // generate shape
    make_shape();

    add_component(&_physics_component);
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
void Asteroid::make_shape(){
  
    // Set radius
    _physics_component.set_radius(_game->rand(_rand_radius_min, _rand_radius_max));

    // Set Velocities
    _physics_component.set_velocity(_game->rand(_rand_forward_velocity_min, _rand_forward_velocity_max));
    _physics_component.set_angular_velocity(_game->rand(_rand_angular_velocity_min, _rand_angular_velocity_max));

    // Get number of vertices
    int vertices = _game->rand(_rand_vertices_min, _rand_vertices_max);

    // Clear vector if nonempty
    _physics_component.clear_shape(); 

    // Fill shape with random angles
    for(int i = 0; i < vertices; ++i){
        _physics_component.add_shape_angle(_game->rand(_rand_angles_min, _rand_angles_max));
    }

}

/** function: draw()
 * 
 * 
 */
std::vector<Vector2d> Asteroid::draw(){
    return _physics_component.draw_shape();
}