/** component_input.cpp
 * 
 * 
 */

#include <vector>
#include "component_input.h"
#include "component_physics.h"
#include "gameobject.h"

/** Constructor
 * 
 */
InputComponent::InputComponent(GameObject* owner, PhysicsComponent& physics_component, int update_order):
    Component(owner, update_order),
    _physics_component(physics_component){

}

/** function update()
 * 
 */
void InputComponent::update(double delta_time){

}

/** function process_input()
 * 
 */
void InputComponent::process_input(std::vector<Game_Action_Code> actions){
    if(_owner->state() == GameObject::GameObject_State_Code::active
    || _owner->state() == GameObject::GameObject_State_Code::resurrected){
        for(auto action: actions){
            switch(action){

                case Game_Action_Code::go_backward:
                    _physics_component.move_backward();
                    break;
                
                case Game_Action_Code::thrust_forward:
                    _physics_component.thrust_forward();
                    break;

            case Game_Action_Code::rotate_left:
                    _physics_component.move_clockwise();
                    break;

            case Game_Action_Code::rotate_right:
                    _physics_component.move_counterclockwise();
                    break;

            case Game_Action_Code::shoot_laser:
                    // Shoot laser
                    break;
                
                case Game_Action_Code::destroy:
                    // Self-destruct (animation)?
                    break;

            }
        }
    }
}

