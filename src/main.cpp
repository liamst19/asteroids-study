/** main.cpp
 *
 * Program entry point.
 * 
 */

#include <iostream>
#include "game.h"
#include "medialayer/medialayer_sdl.h"

int main(int argc, char* argv[]){
  
  std::cout << "Starting Program" << std::endl;

  int return_value = 0;

  // Dimensions of the game window
  const int win_width = 720;
  const int win_height = 480;

  // If I wanted to switch between different media layers, here would probably be the best.
  MediaLayer_SDL media_layer;

  // Create the game object
  Game game;

  // Initialize and run game loop
  if(game.initialize(&media_layer, win_width, win_height)){
    game.run_loop();
  } else{
    return_value = 1; // something went wrong
  }

  // End of game, shut down
  game.shutdown();

  std::cout << "Ending Program" << std::endl;

  return 0;
}