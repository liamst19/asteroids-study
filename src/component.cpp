/** component.cpp
 * 
 * 
 */

#include "component.h"

/**
 * 
 * 
 */
Component::Component(GameObject* owner, int update_order):
    _owner(owner),
    _update_order(update_order)
{}
