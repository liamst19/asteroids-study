/** game.h
 *
 * Game entry point.
 * 
 */

#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include "medialayer.h"

class Game{

public:

    Game():
    _media_layer(nullptr)
    {};

    ~Game(){};

    // Initializes Game
    bool initialize();

    // Initializes Game with media layer
    bool initialize(MediaLayer* media_layer);

    // Initializes Game with media layer and window dimension
    bool initialize(MediaLayer* media_layer, int window_width, int window_height);

    // Runs game loop
    void run_loop();

    // Shuts down game
    void shutdown();

private:
    bool _is_running;
    int _window_width{720};
    int _window_height{480};
    MediaLayer* _media_layer;

    // Retrieves and handles keyboard input from media layer
    void process_input();

    // Update game objects
    void update_game();

    // Renders updated game objects
    void generate_output();

};
#endif