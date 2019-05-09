/** main.cpp
 *
 * Program entry point.  
 */

#include <iostream>
#include "game.h"

int main(int argc, char* argv[]){
  
  std::cout << "Starting Program" << std::endl;

  Game game;
  if(game.initialize()){
    game.run_loop();
  }
  game.shutdown();

  return 0;
}