/** medialayer_sdl_texture.h
 * 
 *  SDL texture wrapper class for rendering images and text texture
 */

#ifndef MEDIALAYER_SDL_TEXTURE_H 
#define MEDIALAYER_SDL_TEXTURE_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class MediaLayer_SDL_Texture{

public:

    MediaLayer_SDL_Texture();

    // Deallocates memory
    ~MediaLayer_SDL_Texture();

    // Loads image from specific path
    bool load_image(std::string path);

    // Creates image from font string, with color
    bool load_text(std::string text, SDL_Color color);

    // Deallocates texture
    void free();

    void set_renderer(SDL_Renderer* renderer){ _renderer = renderer; }

    void set_font_src(std::string font_src){ _font_src = font_src; }

    void set_font_size(int size){ _font_size = size; }

    // Set color modulation
    void set_color(Uint8 red, Uint8 green, Uint8 blue);

    // Set blending
    void set_blending(SDL_BlendMode blending);

    // Set alpha modulation
    void set_alpha(Uint8 alpha);

    // Renders texture at given point
    void render(int x, 
                int y, 
                SDL_Rect* clip = NULL, 
                double angle = 0.0, 
                SDL_Point* center = NULL, 
                SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    // Gets image width
    int width();

    // Gets image height
    int height();

private:

    SDL_Renderer* _renderer;
    TTF_Font* _font;
    std::string _font_src;
    int _font_size{12};

    // SDL texture
    SDL_Texture* _texture;

    // Dimensions
    int _width, _height;

};

#endif