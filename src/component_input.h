/** component_input.h
 * 
 * 
 */
#ifndef COMPONENT_INPUT_H
#define COMPONENT_INPUT_H

#include "component.h"

class InputComponent: public Component{

    InputComponent(GameObject* owner, int update_order = 10);

    ~InputComponent();

    void update(double delta_time) override;
    void process_input(Game_Action_Code action) override;

};

#endif