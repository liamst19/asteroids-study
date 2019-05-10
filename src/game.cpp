/** game.cpp
 *
 */
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
    MEDIALAYER_KEY_CODE key = MediaLayer::MediaLayer_GetInput(_media_layer);

    switch(key){
        case MEDIALAYER_KEY_QUIT:
             MEDIALAYER_KEY_ESC:
            _is_running = false;
            break;
    }
}

/** function: update_game()
 * 
 * 
 */
void Game::update_game(){

    // get delta time
    double delta = MediaLayer::MediaLayer_GetDeltaTime(_media_layer);

 }

/** function: generate_output()
 * 
 * 
 */
void Game::generate_output(){
    MediaLayer::MediaLayer_GenerateOutput(_media_layer);
 }