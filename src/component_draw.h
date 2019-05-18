/** component_draw.h
 * 
 * 
 */
#ifndef COMPONENT_DRAW_H
#define COMPONENT_DRAW_H

#include <vector>
#include "math.h"
#include "component.h"

class DrawComponent: public Component{

public:

    DrawComponent(GameObject* owner, int update_order = 10);

    ~DrawComponent(){};

    // Prepare object to be rendered
    void update(double delta_time) override;

    void process_input(std::vector<Game_Action_Code> actions) override;

    void set_shape_active(std::vector<Vector2d> shape){ _shape_active = shape; }
    void set_shape_destroyed(std::vector<Vector2d> shape){ _shape_destroyed = shape; }

    // Reposition and rotate the shape
    std::vector<Vector2d> draw_shape(Vector2d position, float rotation);

private:

    // Collection of vertices that form shape of the object
    std::vector<Vector2d> _shape_active;
    std::vector<Vector2d> _shape_destroyed;

    std::vector<Vector2d> transform_shape(std::vector<Vector2d> base_shape, Vector2d position, float rotation);

};

#endif