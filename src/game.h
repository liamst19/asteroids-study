/** game.h
 *
 * Game entry point.
 */

#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>

class Game{

public:

    Game(){};
    ~Game(){};

    bool initialize();
    void run_loop();
    void shutdown();

};
#endif