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