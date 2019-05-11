/** game.cpp
 *
 */

#include <vector>
#include "component.h"
#include "gameobject.h"
#include "game.h"
#include "medialayer.h"

/* --------------------------------------------------
/* Public

/** function: initialize()
 * 
 * 
 */
bool Game::initialize(){

    if(_media_layer == nullptr){
        // throw exception: media layer is not initialized
        return false;
    } else if(_window_width <= 0 || _window_height <= 0){
        // throw exception: invalid window size
        return false;
    }

    bool initialized = true;
    initialized = MediaLayer::MediaLayer_Initialize(_media_layer, _window_width, _window_height);

    // Create game objects --------------------------------------

    // -- create asteroids
    // -- create player ship

    // ----------------------------------------------------------

    return initialized;
}

/** function: initialize()
 * 
 * 
 */
bool Game::initialize(MediaLayer* media_layer, int window_width, int window_height){

    _window_width = window_width;
    _window_height = window_height; 
    _media_layer = media_layer;

    return initialize();
}

/** function: run_loop()
 * 
 * 
 */
void Game::run_loop(){

    _is_running = true;

    while(_is_running){
        process_input();
        update_game();
        generate_output();
    }

}

/** function: shutdown()
 * 
 * 
 */
void Game::shutdown(){
    if(_media_layer != nullptr){
        MediaLayer::MediaLayer_Shutdown(_media_layer);
    }
}

/* --------------------------------------------------
/* Private

/** function: process_input()
 * 
 * 
 */
void Game::process_input(){
    Medialayer_Key_Code key = MediaLayer::MediaLayer_GetInput(_media_layer);

    if(key == Medialayer_Key_Code::quit || key == Medialayer_Key_Code::esc){
        // Exit game
        _is_running = false;
        return;
    } else if(key != Medialayer_Key_Code::null){
        // Convert keyboard input to action code
        Component::Game_Action_Code g_action = map_action(key);

        // iterate through game objects and run process_input()
        for(auto gameobj: _game_objects){
            gameobj->process_input(g_action);
        }
    }

}

/** function: update_game()
 * 
 * 
 */
void Game::update_game(){

    // get delta time
    double delta_time = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

    // iterate through game objects and run update()
    for(auto gameobj: _game_objects){
        gameobj->update(delta_time);
        // if object is destroyed, remove from vector
        // flag respawn smaller asteroids if destroyed
    }

    // respawn asteroids

    // if ship is destroyed, respawn ship

 }

/** function: generate_output()
 * 
 * 
 */
void Game::generate_output(){

    // iterate through and render game objects

    MediaLayer::MediaLayer_GenerateOutput(_media_layer);
 }

 /** function map_action()
  * 
  * Convert keyboard input to game action
  * 
  * Note: Could there be an instance where there are 
  * two actions with one key input?
  * 
  * Note: In most games keys can be remapped by player.
  * 
  */
Component::Game_Action_Code Game::map_action(Medialayer_Key_Code key){
    Component::Game_Action_Code action{Component::Game_Action_Code::nothing};

    switch(key){
        case Medialayer_Key_Code::w:
            action = Component::Game_Action_Code::accelerate;
            break;
        
        case Medialayer_Key_Code::a:
            action = Component::Game_Action_Code::rotate_left;
            break;
        
        case Medialayer_Key_Code::s:
            action = Component::Game_Action_Code::decelerate;
            break;

        case Medialayer_Key_Code::d:
            action = Component::Game_Action_Code::rotate_right;
            break;

        case Medialayer_Key_Code::spc:
            action = Component::Game_Action_Code::shoot_laser;
            break;
    }

    return action;
} 