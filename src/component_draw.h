/** component_draw.h
 * 
 * 
 */
#ifndef COMPONENT_DRAW_H
#define COMPONENT_DRAW_H

#include "component.h"

class DrawComponent: public Component{

public:

    DrawComponent(GameObject* owner, int update_order = 10);

    ~DrawComponent(){};

    // Prepare object to be rendered
    void update(double delta_time) override;

    void process_input(Game_Action_Code action) override;

private:

};

#endif