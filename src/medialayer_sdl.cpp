/** medialayer_sdl.cpp
 *
 * 
 * 
 */

#include <SDL2/SDL.h>
#include "medialayer_sdl.h"

// --------------------------------------------------
// Public

/* function: initialize()
 *
 * 
 */
bool MediaLayer_SDL::initialize(){
    bool initialized = false;

    initialized = create_window();
    initialized = create_renderer();

    return initialized;
}

/* function: initialize()
 *
 * 
 */
bool MediaLayer_SDL::initialize(int window_width, int window_height, int window_x, int window_y){
    _window_width = window_width;
    _window_height = window_height;
    _win_coordinate_x = window_x;
    _win_coordinate_y = window_y;
    return initialize();
}

/* function: initialize()
 *
 * 
 */
bool MediaLayer_SDL::initialize(int window_width, int window_height){
    return initialize(window_width, window_height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

/* function: shutdown()
 *
 * 
 */
void MediaLayer_SDL::shutdown(){
    SDL_DestroyRenderer(_renderer);
    _renderer = nullptr;
    SDL_DestroyWindow(_window);
    _window = nullptr;
    SDL_Quit();
}

/* function: create_window()
 *
 * 
 */
bool MediaLayer_SDL::create_window(){

    _window = SDL_CreateWindow("Study",
                               _win_coordinate_x,
                               _win_coordinate_y,
                               _window_width,
                               _window_height,
                               _sdl_flag);
  if(!_window){
    SDL_Log("Failed to create window: %s", SDL_GetError());
    // Throw exception
    return false;
  };

  return true;
}

/* function: create_renderer()
 *
 * 
 */
bool MediaLayer_SDL::create_renderer(){
    // create renderer
    _renderer = SDL_CreateRenderer(
            _window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if(!_renderer){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        // Throw exception
        return false;
    }

    return true;
}

/* function: get_input()
 *
 * 
 */
MEDIALAYER_KEY_CODE MediaLayer_SDL::get_input(){
    
    // Close Window
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            return MEDIALAYER_KEY_QUIT;
            break;
        };
    };

    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_ESCAPE]){
        return MEDIALAYER_KEY_ESC;
    };
    if(state[SDL_SCANCODE_W]){
        return MEDIALAYER_KEY_W;
    }
    if(state[SDL_SCANCODE_A]){
        return MEDIALAYER_KEY_A;
    }
    if(state[SDL_SCANCODE_S]){
        return MEDIALAYER_KEY_S;
    }
    if(state[SDL_SCANCODE_D]){
        return MEDIALAYER_KEY_D;
    }
    if(state[SDL_SCANCODE_SEMICOLON]){
        return MEDIALAYER_KEY_SEMICOLON;
    }

    // Return null
    return MEDIALAYER_KEY_NULL;
}

/* function: draw()
 *
 * 
 */
void MediaLayer_SDL::draw(){

}

/* function: generate_output()
 *
 * 
 */
void MediaLayer_SDL::generate_ouput(){

    SDL_SetRenderDrawColor(_renderer,
                            0,
                            0,
                            255,
                            255);
    SDL_RenderClear(_renderer);

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    
    SDL_RenderPresent(_renderer);
}

/* function: delta_time()
 *
 * 
 */
double MediaLayer_SDL::delta_time(){
    return (SDL_GetTicks() - _ticks_count) / 1000.0;
}