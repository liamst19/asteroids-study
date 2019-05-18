/** game.cpp
 *
 */

#include <SDL2/SDL.h>
#include <vector>
#include "randomnumber.h"
#include "medialayer.h"
#include "game.h"
#include "component.h"
#include "gameobject.h"
#include "gameobject_asteroid.h"
#include "gameobject_ship.h"

/* --------------------------------------------------
/* Public

/** function: initialize()
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
    create_asteroids();
    create_ship();
    // ----------------------------------------------------------

    return initialized;
}

/** function: initialize()
 * 
 */
bool Game::initialize(MediaLayer* media_layer, int window_width, int window_height){

    _window_width = window_width;
    _window_height = window_height; 
    _media_layer = media_layer;

    return initialize();
}

/** function:: create_asteroids()
 * 
 */
void Game::create_asteroids(){
    
    int count{rand(10, 50)};

    for(int i = 0; i <= count; ++i){
        
        Vector2d position{static_cast<float>(rand(0, _window_width)), 
                          static_cast<float>(rand(0, _window_height))};

        float rotation{static_cast<float>(rand(1, 360))};

        _game_objects.push_back(new Asteroid{this, 
                                             position,
                                             rotation}
                               );
    }
}

/** function: create_ship()
 * 
 */
void Game::create_ship(){
    _game_objects.push_back(new Ship(this, Vector2d(_window_width/2, _window_height/2)));
}

/** function: run_loop()
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
 */
void Game::shutdown(){
    if(_media_layer != nullptr){
        MediaLayer::MediaLayer_Shutdown(_media_layer);
    }

    if(!_game_objects.empty()){
        for(auto obj: _game_objects){
            delete obj;
        }
    }
}

/* --------------------------------------------------
/* Private

/** function: process_input()
 * 
 */
void Game::process_input(){
    std::vector<Medialayer_Key_Code> key_codes = MediaLayer::MediaLayer_GetInput(_media_layer);
    std::vector<Component::Game_Action_Code> action_codes;

    for(auto key: key_codes){
    
        // Check for exit
        if(key == Medialayer_Key_Code::quit || key == Medialayer_Key_Code::esc){
            // Exit game
            _is_running = false;
            return;
        } else if(key != Medialayer_Key_Code::null){
            // Convert keyboard input to action code
            action_codes.push_back(map_action(key));
        }
    }
    
    // iterate through game objects and run process_input()
    for(auto gameobj: _game_objects){
        gameobj->process_input(action_codes);
    }
}

/** function: update_game()
 * 
 */
void Game::update_game(){

    // get delta time
    double delta_time = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

    // iterate through game objects and run update()
    for(auto gameobj: _game_objects){
        gameobj->update(delta_time);
        // collision
        // if object is destroyed, remove from vector
        // flag respawn smaller asteroids if destroyed
    }

    // respawn asteroids

    // if ship is destroyed, respawn ship

 }

/** function: generate_output()
 * 
 */
void Game::generate_output(){
    _media_layer->clear_shapes();

    // iterate through and render game objects
    for(auto gameobj: _game_objects){
        _media_layer->add_shape(gameobj->draw());
    }

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
            action = Component::Game_Action_Code::thrust_forward;
            break;
        
        case Medialayer_Key_Code::a:
            action = Component::Game_Action_Code::rotate_left;
            break;
        
        case Medialayer_Key_Code::s:
            action = Component::Game_Action_Code::go_backward;
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

/** function: rand()
 * 
 */
int Game::rand(int min, int max){
    return _rand.rand(min, max);
}