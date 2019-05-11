/** component_draw.h
 * 
 * 
 */
#ifndef COMPONENT_DRAW_H
#define COMPONENT_DRAW_H

#include "component.h"

class DrawComponent: public Component{

    DrawComponent(GameObject* owner, int update_order = 10);

    ~DrawComponent();

    void update(double delta_time) override;
    void process_input(Game_Action_Code action) override;

};

#endif