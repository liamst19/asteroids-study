/** component_input.cpp
 * 
 * 
 */

#include "component_input.h"
#include "component_physics.h"

/** Constructor
 * 
 * 
 */
InputComponent::InputComponent(GameObject* owner, PhysicsComponent& physics_component, int update_order):
    Component(owner, update_order),
    _physics_component(physics_component){

}

/** function update()
 * 
 * 
 */
void InputComponent::update(double delta_time){

}

/** function process_input()
 * 
 * 
 */
void InputComponent::process_input(Game_Action_Code action){

    switch(action){

        case Game_Action_Code::go_backward:
            _physics_component.move_backward();
            break;
        
        case Game_Action_Code::go_forward:
            _physics_component.move_forward();
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

