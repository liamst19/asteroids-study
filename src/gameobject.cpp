/** gameobject.cpp
 * 
 * 
 */

#include <vector>
#include "component.h"
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
void GameObject::process_input(Component::Game_Action_Code action){
    // Iterate through components and run process_input()
    for(Component* component: _components){
        component->process_input(action);
    }
}

/** function: update()
 * 
 * 
 */
void GameObject::update(double delta_time){

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
    for(Component* component: _components){
        component->update(delta_time);
    }
}
