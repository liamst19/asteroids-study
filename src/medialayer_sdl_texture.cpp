/** medialayer_sdL_texture.cpp
 * 
 *  Based on Lazy Foo Productions Tutorial
 *  on True Type Fonts
 *  https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
 * 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

#include "medialayer_sdl_texture.h"

/** Constructor
 * 
 */
MediaLayer_SDL_Texture::MediaLayer_SDL_Texture():
    _texture{NULL},
    _width{0},
    _height{0}
{
}

/** Destructor
 * 
 */
MediaLayer_SDL_Texture::~MediaLayer_SDL_Texture()
{
    // Deallocate
    free();
}

/** function: load_image()
 * 
 */
bool MediaLayer_SDL_Texture::load_image(std::string path){

    free();

    // The final texture
    SDL_Texture* new_texture{NULL};
    // Load image at specified path
    SDL_Surface* loaded_surface{IMG_Load(path.c_str())};

    if(loaded_surface == NULL){
        // failed to load image
        SDL_Log("Unable to load image %s : SDL_image Error: %s", path.c_str(), IMG_GetError());
    } else{
        //Color key image
        SDL_SetColorKey(loaded_surface, 
                        SDL_TRUE, 
                        SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));
        
        // Create texture
        new_texture = SDL_CreateTextureFromSurface(_renderer, loaded_surface);
        if(new_texture == NULL){
            SDL_Log("Unable to create texture from %s : SDL Error: %s", path.c_str(), SDL_GetError());
        } else{
            // Get dimensions
            _width = loaded_surface->w;
            _height = loaded_surface->h;
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loaded_surface);
    }

    //Return
    _texture = new_texture;
    return _texture != NULL;
}

/** function: load_text()
 * 
 */
bool MediaLayer_SDL_Texture::load_text(std::string text, SDL_Color color){

	//Get rid of preexisting texture
	free();

    _font = TTF_OpenFont(_font_src.c_str(), _font_size);

    if(_font == nullptr){
        SDL_Log("Unable to load font");
        return false;
    }

	//Render text surface
	SDL_Surface* text_surface = TTF_RenderText_Solid(_font, text.c_str(), color);

	if( text_surface == nullptr )
	{
		SDL_Log( "Unable to render text surface. SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        _texture = SDL_CreateTextureFromSurface(_renderer, text_surface);

		if(_texture == nullptr)
		{
			SDL_Log( "Unable to create texture from rendered text. SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			_width = text_surface->w;
			_height = text_surface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( text_surface );
	}

    TTF_CloseFont(_font);	

	//Return success
	return _texture != NULL;
}

/** function: free()
 * 
 */
void MediaLayer_SDL_Texture::free(){
    // Free texture
    if(_texture != nullptr){
        SDL_DestroyTexture(_texture);
        _texture = NULL;
        _width = 0;
        _height = 0;
    }

    if(_font != nullptr){
        // TTF_CloseFont(_font);
        _font = NULL;
    }

}

/** function: set_color()
 * Modulate texture RGB
 */
void MediaLayer_SDL_Texture::set_color(Uint8 red, Uint8 green, Uint8 blue){
    SDL_SetTextureColorMod(_texture, red, green, blue);
}

/** function: set_blending()
 * Set blending function
 */
void MediaLayer_SDL_Texture::set_blending(SDL_BlendMode blending){
    SDL_SetTextureBlendMode(_texture, blending);
}

/** function: set_alpha()
 *  Modulate texture alpha 
 */
void MediaLayer_SDL_Texture::set_alpha(Uint8 alpha){
    SDL_SetTextureAlphaMod(_texture, alpha);
}

/** function: render()
 * 
 */
void MediaLayer_SDL_Texture::render(int x, 
                        int y, 
                        SDL_Rect* clip, 
                        double angle, 
                        SDL_Point* center, 
                        SDL_RendererFlip flip){

    // Set rendering space and render to screen
    SDL_Rect render_quad{x, y, _width, _height};
    if(clip != NULL){
        render_quad.w = clip->w;
        render_quad.h = clip->h;
    }

    //Render
    SDL_RenderCopyEx(_renderer, 
                     _texture, 
                     clip, 
                     &render_quad, 
                     angle, 
                     center, 
                     flip);
}

/** function: width()
 * 
 */
int MediaLayer_SDL_Texture::width(){
    return _width;
}

/** function: height()
 * 
 */
int MediaLayer_SDL_Texture::height(){
    return _height;
}