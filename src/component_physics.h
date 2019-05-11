/** component_physics.h
 * 
 * 
 */
#ifndef COMPONENT_PHYSICS_H
#define COMPONENT_PHYSICS_H

#include "component.h"

class PhysicsComponent: public Component{

    PhysicsComponent(GameObject* owner, int update_order = 10);

    ~PhysicsComponent();

    void update(double delta_time) override;
    void process_input(Game_Action_Code action) override;

};

#endif