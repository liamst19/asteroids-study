/** component.h
 * 
 * 
 */
#ifndef COMPONENT_H
#define COMPONENT_H

class GameObject; // Forward Declare

class Component{

public:

    enum class Game_Action_Code{
        nothing         = 0,
        shoot_laser     = 3,
        thrust_forward  = 4,
        rotate_left     = 5,
        go_backward     = 6,
        rotate_right    = 7,
        destroy         
    };

    Component(GameObject* owner, int update_order);

    virtual ~Component(){};

    // Process Input
    virtual void process_input(Game_Action_Code action) =0;

    // Update
    virtual void update(double delta_time) =0;

    // Get rendering position
    int get_update_order() const { return _update_order; };

protected:

    GameObject* _owner; // GameObject which owns this component
    int _update_order;  // Rendering position

};

#endif