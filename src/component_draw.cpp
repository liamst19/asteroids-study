/** component_draw.cpp
 * 
 * 
 */

#include <vector>
#include "component_draw.h"
#include "math.h"

/** Constructor
 *
 * 
 */
DrawComponent::DrawComponent(GameObject* owner, int update_order):
    Component(owner, update_order){

}

/** function update()
 * 
 * 
 */
void DrawComponent::update(double delta_time){

}

/** function process_input()
 * 
 * 
 */
void DrawComponent::process_input(std::vector<Game_Action_Code> actions){

}

/** function: draw_shape()
 * 
 * 
 */
std::vector<Vector2d> DrawComponent::draw_shape(Vector2d position, float rotation){

    std::vector<Vector2d> shape;

    float radians = Math::ToRadians(rotation);
    float sin_r = Math::Sin(radians);
    float cos_r = Math::Cos(radians);

    for(auto point: _shape){
        shape.push_back(Vector2d(
            position.x + (cos_r * point.x - sin_r * point.y),
            position.y - (sin_r * point.x + cos_r * point.y)
        ));
    }

    return shape;
}