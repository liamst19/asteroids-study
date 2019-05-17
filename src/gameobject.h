/** gameobject.h
 * 
 * 
 */
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "math.h"
#include "component_physics.h"

class Game; // Forward Declare

class GameObject{

public:

    enum {
        active,
        inactive,
        destroyed
    };

    GameObject(Game* game);

    virtual ~GameObject(){};

    // Process input
    void process_input(Component::Game_Action_Code action);

    // Update
    virtual void update(double delta_time) =0;
    
    // Draw object: return a vector containing path coordinates,
    // or perhaps a vector of shape objects, each containing instructions 
    virtual std::vector<Vector2d> draw() =0;

    Vector2d get_bounds();

protected:
    Game* _game;

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