## Notes

- Texts/Fonts
  - [Lazy Foo' Productions has a tutorial on handling True Type Fonts using SDL and SDL_TTF libraries.](https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php)
- Is `MediaLayer` really necessary? Are there situations where one needs handle possibility of multiple media libraries (SDL, DirectX, etc.)? Is this something I should be thinking about?
    - Suppose I'm making a rogue-like. There is an option between using tiles (SDL) and `ncurses`. Would this be an effective way to simplify output?
- And is the name "medialayer" acceptable for what the code does, wrapping and hiding the SDL (Simple DirectMedia Layer)?
- Imagine a vast open universe, where much of the objects won't show up on screen. It would be impractical to do anything that has to do with rendering (i.e., draw component).

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
