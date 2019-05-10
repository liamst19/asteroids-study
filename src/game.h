/** game.h
 *
 * Game entry point.
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

    bool initialize();
    bool initialize(MediaLayer* media_layer, int window_width, int window_height);
    void run_loop();
    void shutdown();

private:
    bool _is_running;
    int _window_width{720};
    int _window_height{480};
    MediaLayer* _media_layer;

    void process_input();
    void update_game();
    void generate_output();

};
#endif