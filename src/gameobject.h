/** gameobject.h
 * 
 * 
 */
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "math.h"
#include "component_collision.h"
#include "component_physics.h"
#include "component_draw.h"


class Game; // Forward Declare

class GameObject{

public:

    enum class GameObject_State_Code{
        active,
        inactive,
        destroyed
    };

    GameObject(Game* game, Vector2d position, float rotation);

    virtual ~GameObject(){};

    // Process input
    void process_input(std::vector<Component::Game_Action_Code> actions);

    // Update
    virtual void update(double delta_time) =0;
    
    // Draw object: return a vector containing path coordinates,
    // or perhaps a vector of shape objects, each containing instructions 
    virtual std::vector<Vector2d> draw() =0;

    // Get boundary info: the screen dimension
    Vector2d get_bounds();

    // Get collection of game objects in existence
    std::vector<GameObject*> game_objects();

    // State ------------------------------

    void set_state(GameObject_State_Code state){ _state = state; }

    GameObject_State_Code state(){ return _state; }

    virtual void destroy() =0;

    // Position and Velocity --------------

    Vector2d position() const;

    float rotation() const;

    Vector2d velocity() const;

    // Collision --------------------------

    bool collide(const CollisionComponent& object);

    float collision_angle(const CollisionComponent& object);

    CollisionComponent& collision_component(){ return _collision; }

protected:
    Game* _game;
    GameObject_State_Code _state;

    CollisionComponent  _collision;
    DrawComponent       _draw;
    PhysicsComponent    _physics;

    const int _component_count{5};

    double _destroyed_delta;
    const double _resurrect_delta{3.0};

    // Update Game Object
    void update_gameobject(double delta_time);

    // Add Component to the fame object
    void add_component(Component* component);

    // Update Components
    void update_components(double delta_time);

private:

    std::vector<Component*> _components;

};

#endif