/** gameobject.cpp
 * 
 * 
 */

#include <vector>
#include "math.h"
#include "component.h"
#include "game.h"
#include "gameobject.h"

/** GameObject Constructor
 * 
 * 
 */
GameObject::GameObject(Game* game):
    _game(game)
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

Vector2d GameObject::get_bounds(){ return _game->get_bounds(); }

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
