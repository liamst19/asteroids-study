/** gameobject.cpp
 * 
 * 
 */

#include <vector>
#include "math.h"

#include "gameobject.h"
#include "game.h"
#include "component.h"
#include "component_collision.h"

/** GameObject Constructor
 * 
 * 
 */
GameObject::GameObject(Game* game, Vector2d position, float direction, float rotation):
    _game(game),
    _state(GameObject_State_Code::active),
    _physics(this, position, direction, rotation, 0, Vector2d(), 22),
    _draw(this, 3),
    _collision(this, _physics, 4)
{}

/** function: process_input()
 * 
 * 
 */
void GameObject::process_input(std::vector<Component::Game_Action_Code> actions){
    // Iterate through components and run process_input()
    for(auto component: _components){
        component->process_input(actions);
    }
}
    
//}

Vector2d GameObject::get_bounds(){ 
    return _game->get_bounds(); 
}

std::vector<GameObject*> GameObject::game_objects(){ 
    return _game->game_objects(); 
}

bool GameObject::collide(const CollisionComponent& object){
    return _collision.collide(object);
}

float GameObject::collision_angle(const CollisionComponent& object){
    return _collision.collision_angle(object);
}

Vector2d GameObject::position() const{
    return _physics.position();
}

Vector2d GameObject::velocity() const{
    return _physics.velocity();
}


// ----------------------------------------------------------------------
// protected 

/** function: update_gameobject()
 * 
 * 
 */
void GameObject::update_gameobject(double delta_time){

}

/** function: add_component()
 * 
 * 
 */
void GameObject::add_component(Component* component){
    // Insert component
    _components.push_back(component);
}

/** function: update_components()
 * 
 * 
 */
void GameObject::update_components(double delta_time){
    // Iterate through components and run update()
    for(auto component: _components){
        component->update(delta_time);
    }
}
