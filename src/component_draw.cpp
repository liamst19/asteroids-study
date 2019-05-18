/** component_draw.cpp
 * 
 * 
 */
#include <vector>
#include "math.h"
#include "component_draw.h"
#include "gameobject.h"

/** Constructor
 *
 */
DrawComponent::DrawComponent(GameObject* owner, int update_order):
    Component(owner, update_order){

}

/** function update()
 * 
 */
void DrawComponent::update(double delta_time){

}

/** function process_input()
 * 
 */
void DrawComponent::process_input(std::vector<Game_Action_Code> actions){

}

/** function: draw_shape()
 * 
 */
std::vector<Vector2d> DrawComponent::draw_shape(Vector2d position, float rotation){
    std::vector<Vector2d> shape;

    // Draw according to the object's state
    switch(_owner->state()){
        case GameObject::GameObject_State_Code::resurrected:
        case GameObject::GameObject_State_Code::active:
            shape = transform_shape(_shape_active, position, rotation);
            break;
        case GameObject::GameObject_State_Code::destroyed:
            shape = transform_shape(_shape_destroyed, position, rotation);
            break;
        case GameObject::GameObject_State_Code::inactive:
            //
            break;
    }

    return shape;
}

/** function: draw_shape_active()
 * 
 */
std::vector<Vector2d> DrawComponent::transform_shape(std::vector<Vector2d> base_shape, Vector2d position, float rotation){
    std::vector<Vector2d> shape;

    float radians = Math::ToRadians(rotation);
    float sin_r = Math::Sin(radians);
    float cos_r = Math::Cos(radians);

    for(auto point: base_shape){
        shape.push_back(Vector2d(
            position.x + (cos_r * point.x - sin_r * point.y),
            position.y - (sin_r * point.x + cos_r * point.y)
        ));
    }

    return shape;
}
