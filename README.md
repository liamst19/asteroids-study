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