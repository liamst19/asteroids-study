/** gameobject.h
 * 
 * 
 */
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "component.h"

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
    void update(double delta_time);

protected:

    // Update Game Object
    void update_gameobject(double delta_time);

    // Add Component to the fame object
    void add_component(Component* component);

    // Update Components
    void update_components(double delta_time);

private:

    Game* _game;
    std::vector<Component*> _components;
};

#endif