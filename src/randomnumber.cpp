/** randomnumber.cpp
 * 
 * 
 */
#include "randomnumber.h"

int RandomNumber::rand(int min, int max){
   return std::uniform_int_distribution<int>{min, max}(_generator);
}