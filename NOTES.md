# Notes

- Is `MediaLayer` really necessary? Are there situations where one needs handle possibility of multiple media libraries (SDL, DirectX, etc.)? Is this something I should be thinking about?
    - Suppose I'm making a rogue-like. There is an option between using tiles (SDL) and `ncurses`. Would this be an effective way to simplify output?
- And is the name "medialayer" acceptable for what the code does, wrapping and hiding the SDL (Simple DirectMedia Layer)?

## TODO

- The code from the book used sprite images, but the original *Asteroids* apparently were drawn. Figure out how to draw asteroids.
    - an asteroid would have a center and radius
    - should shapes be randomly generated, or should there be several hand-coded templates?
- My initial guess is that following components would be necessary to handle player ship and asteroids:
    - Graphics: handles instructions for rendering shapes, and possibly animation
    - Physics: handles positions, rotation, vectors, velocities, and collision
    - Input?: handles player spaceship input
- Shooting down asteroids
    - Would lasers also be an object with its own physics and graphics?
- Animation
    - Ship thrusters
    - Ship laser
    - Ship destruction
    - Asteroid destruction
- Background: draw distant stars?
- Sound: probably not.

## Graphics

For drawing ship and asteroids, there seems to be several options to go about: 
```
int SDL_RenderDrawLine (SDL_Renderer* renderer,
                       int           x1,
                       int           y1,
                       int           x2,
                       int           y2)

int SDL_RenderDrawLines (SDL_Renderer* renderer,
                        const SDL_Point* points,
                        int              count)

int SDL_RenderDrawPoint (SDL_Renderer* renderer,
                        int           x, 
                        int           y)

int SDL_RenderDrawPoints (SDL_Renderer* renderer,
                         const SDL_Point* points,
                         int              count)

```
[`SDL_RenderDrawLines`](https://wiki.libsdl.org/SDL_RenderDrawLines) appears to be the simplest, drawing along a path of array of points. I suppose that `DrawComponent` object would contain an array of coordinates that plot a path, which would be transformed (moved and rotated) upon `update()`, and converted to an array of `SDL_Point`s upon `generate_output()` call. 

Perhaps it would also be good exercise to try porting to OpenGL in the future. 