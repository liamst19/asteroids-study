/** medialayer_sdl.h
 *
.* Inherits MediaLayer for handling keyboard inputs 
 * and outputs to screen.
 * 
 * 
 * 
 */
#ifndef MEDIALAYER_SDL
#define MEDIALAYER_SDL

#include <SDL2/SDL.h> // hopefully this is contained
#include "medialayer.h"

class MediaLayer_SDL: public MediaLayer{

public:
  
    MediaLayer_SDL():
    _window(nullptr),
    _renderer(nullptr){};

    MediaLayer_SDL(int window_width, int window_height, int window_x, int window_y)
    {
        _window_width = window_width;
        _window_height = window_height;
        _win_coordinate_x = window_x;
        _win_coordinate_y = window_y;
        MediaLayer_SDL();
    };

    MediaLayer_SDL(int window_width, int window_height){
        MediaLayer_SDL(window_width, window_height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    };

    ~MediaLayer_SDL(){
        // shutdown();
    };

    bool initialize();
    bool initialize(int window_width, int window_height);
    bool initialize(int window_width, int window_height, int window_x, int window_y);
    void shutdown();

    bool create_window();
    MEDIALAYER_KEY_CODE get_input();

    // adds an object to be rendered to a vector
    void draw();

    // iterate through vector and render contents
    void generate_ouput();

    double delta_time();

private:

    SDL_Window* _window;        // Window created by SDL 
    SDL_Renderer* _renderer;    // SDL Renderer
    int _sdl_flag{0};           // SDL Flags: I don't know what this is

    bool create_renderer();

};

#endif