/** component_collision.h
 * 
 * 
 */
#ifndef COMPONENT_COLLISION_H
#define COMPONENT_COLLISION_H

#include <vector>
#include "math.h"
#include "component.h"

class CollisionComponent: public Component{

public:

    CollisionComponent(GameObject* owner, int update_order = 10);

    ~CollisionComponent(){};

    // Prepare object to be rendered
    void update(double delta_time) override;

    void process_input(std::vector<Game_Action_Code> actions) override;

    void set_radius(float radius){ _radius = radius; }

    float radius(){ return _radius; }

    const Vector2d get_center() const;

    static bool intersect(const CollisionComponent& a, const CollisionComponent& b);

 private:

    float _radius;

};

#endif