/** main.cpp
 *
 * Program entry point.  
 */

#include <iostream>
#include "game.h"
#include "medialayer_sdl.h"

int main(int argc, char* argv[]){
  
  std::cout << "Starting Program" << std::endl;

  const int win_width = 720;
  const int win_height = 480;

  Game game;
  MediaLayer_SDL media_layer;

  if(game.initialize(&media_layer, win_width, win_height)){
    game.run_loop();
  }

  game.shutdown();

  std::cout << "Ending Program" << std::endl;

  return 0;
}