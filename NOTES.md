## Notes

- Texts/Fonts
  - [Lazy Foo' Productions has a tutorial on handling True Type Fonts using SDL and SDL_TTF libraries.](https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php)
- Is `MediaLayer` really necessary? Are there situations where one needs handle possibility of multiple media libraries (SDL, DirectX, etc.)? Is this something I should be thinking about?
    - Suppose I'm making a rogue-like. There is an option between using tiles (SDL) and `ncurses`. Would this be an effective way to simplify output?
- And is the name "medialayer" acceptable for what the code does, wrapping and hiding the SDL (Simple DirectMedia Layer)?
- **Rendering**: at the moment, lines are redrawn from vertices at each frame render. Would it be more efficient to create a *texture* with the polygon drawn into it, and at render time reposition and rotate it? Considering the need to render other elements like TTF text, which requires the use of textures, it would be simpler to keep a single vector of texture objects to iterate through, instead of switching between text, circle, line, point, etc.
    - such texture object would probably contain
        - sdl_texture object
        - position
        - rotation
        - id - for updating and redrawing (e.g., message text changes, position change)
        - type - text, circle, point, line, polygon (collection of vertices for SDL_RenderDrawLines)
    - perhaps it would instead be better for the texture object to keep a pointer to a generic draw object containing id, type, and position/rotation, with a boolean flag to check if something needs to be done with sdl_texture itself.
        - To render shapes, lines, points to a texture, 
            1. Create texture: `texture = SDL_CreateTexture(renderer, SDL_GetWindowPixelFormat(window), SDL_TEXTUREACCESS_TARGET, width, height);`
            2. Set render target to a texture with `SDL_SetRenderTarget(renderer, texture);`
            3. Render shapes and lines as you would to a window: `SDL_SetRenderDrawColor()`, `SDL_RenderDrawLines()`, `SDL_RenderDrawRect()`, etc.
            4. Reset `renderer` to render to original window, `SDL_SetRenderTarget(renderer, NULL);`.
        - [On `SDL_RenderDrawTarget()`](https://wiki.libsdl.org/SDL_SetRenderTarget). Notice the `SDL_TEXTUREACCESS_TARGET` flag in `SDL_CreateTexture()`.
        - Would it be better to call `SDL_RenderDrawClear()` and `SDL_RenderDrawPresent()` with targeted texture, instead of deleting, creating new texture, and redrawing? This is however unnecessary with the ship and asteroid objects, as their shapes are locked after creation, and merely are rotated and repositioned. It also seems that with textures from SDL_ttf it would be better to call `SDL_DestroyTexture()` and create anew, [as demonstrated in Lazy Foo's tutorial](https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php).
        - What should happen, with regard to textures, when asteroid is destroyed? Check for `nullptr` and remove? 
- Imagine a vast open universe, where much of the objects won't show up on screen. It would be impractical to do anything that has to do with rendering (i.e., draw component).
- **HUD Interface**

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
