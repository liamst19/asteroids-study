# Asteroids Study

The goal of this project is to create an asteroids game, loosely based on codes that appeared on chapters 2 and 3 of [*Game Programming in C++*](https://www.pearson.com/us/higher-education/program/Madhav-Game-Programming-in-C-Creating-3-D-Games/PGM1102283.html) by Sanjay Madhav.

The primary intentions are:
- to familiarize myself further with C++
- practice the component pattern
- practice handling simple physics within a 2-dimentional game space
- practice testing, using the [google test framework](https://github.com/google/googletest)

## Current State

- Asteroids 
    - they are polygons with randomly generated vertices and radius
    - they collide and bounce off each other
- Ship
    - They rotate and move forward and backward:
        - W: Forward
        - S: Backward
        - A: Rotate counter clockwise
        - D: Rotate clockwise
    - Weapons are not yet implemented
    - There are few seconds of invincibility to get away from overlapping asteroids.
    - Upon collision with an asteroid, it will reset to the center.

![GitHub Logo](/images/screen.jpg)

## Notes on compiling

Since this is merely for personal study I have not worried myself with the problem of compiling from different environments. I have been using cmake from [MSYS2/MinGW64](https://www.msys2.org/), which I think is using the gcc compiler (which comes with the toolchain `$ pacman -S mingw-w64-x86_64-toolchain`). SDL2 library is also required, and if I remember correctly, is available from MSYS2's package manager (pacman) with the command `$ pacman -S mingw-w64-x86_64-SDL2`. An installation of [Git](https://git-scm.com/) is also needed to download the google test framework.

The general compilation workflow I've been going through is the following:

```
$ mkdir build
$ cd build
$ cmake .. -G "MSYS Makefiles"
....
$ cmake --build .
```
That is, create some build directory (`/build`) and move there, prepare Makefiles with cmake (it took some time to figure out that `-G "MSYS Makefiles` is needed in MSYS2), and then building with cmake's `--build` option.

## Other Notes

- Is `MediaLayer` really necessary? Are there situations where one needs handle possibility of multiple media libraries (SDL, DirectX, etc.)? Is this something I should be thinking about?
    - Suppose I'm making a rogue-like. There is an option between using tiles (SDL) and `ncurses`. Would this be an effective way to simplify output?
- And is the name "medialayer" acceptable for what the code does, wrapping and hiding the SDL (Simple DirectMedia Layer)?

### TODO / Wishlist

- The code from the book used sprite images, but the original *Asteroids* apparently were drawn. Figure out how to draw asteroids.
    - ~~an asteroid would have a center and radius~~
    - ~~should shapes be randomly generated, or should there be several hand-coded templates?~~ Asteroids are polygons whose radius and vertices are randomly generated.
- Collision Detection
    - Currently detection is done with a circle, but hope is that area can be reduced to the actual contours
    - Handle overlapping and sticking; since they are kind of fun, at least figure out how to handle them and have the option to improve.
- My initial guess is that following components would be necessary to handle player ship and asteroids:
    - ~~Graphics: handles instructions for rendering shapes, and possibly animation~~
    - ~~Physics: handles positions, rotation, vectors, velocities, and collision~~
    - ~~Input?: handles player spaceship input~~
    These are all implemented now.
- Shooting down asteroids
    - Would lasers also be an object with its own physics and graphics?
    - Should asteroids have HP?
- Interface: HUD
    - Still need to find out how to render fonts
    - Timer for how long a ship can survive without colliding
- Animation
    - Ship thrusters
    - Ship laser
    - Ship destruction
    - Asteroid destruction
- Background: draw distant stars?
- Sound: probably not.
- Wishlist/Brainstorming for expansion:
    - Asteroids would have different properties, e.g. resources like water, energy, ores, and a ship would interact to collect.
    - Resource management: energy, water/food, materials for repair and upgrade
    - Larger universe with generated clusters of asteroids
    - Gravitational pull
    - With larger universe, faster travel like lightspeed warping
    - Ship mechanics: damages, repairing, upgrading
    - Non-Player ships: pirates, friendlies
    - Stations to sell/buy/trade resources, repair