/** component_input.h
 * 
 * 
 */
#ifndef COMPONENT_INPUT_H
#define COMPONENT_INPUT_H

#include <vector>
#include "component.h"

class PhysicsComponent;

class InputComponent: public Component{

public:

    InputComponent(GameObject* owner, PhysicsComponent& physics_component, int update_order = 10);

    ~InputComponent(){};

    void update(double delta_time) override;

    // Handle keyboard input
    void process_input(std::vector<Game_Action_Code> actions) override;

private:

    PhysicsComponent& _physics_component;
};

#endif