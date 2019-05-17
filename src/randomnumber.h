/** randomnumber.h
 * 
 * 
 */
#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <random>
#include <memory>
#include <ctime>
#include <functional>

class RandomNumber{

public:

    RandomNumber():
    _seed{r(),r(),r(),r(),r(),r(),r(),r()},
    _generator{_seed}
    {};

    int rand();
    int rand(int min, int max);

private:
    std::random_device r;
    std::seed_seq _seed;
    std::mt19937_64 _generator;
};

#endif