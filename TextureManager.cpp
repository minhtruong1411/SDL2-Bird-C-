#include "TextureManager.h"

SDL_Texture* TextureManager:: TexTure(const char* filelocation,SDL_Renderer *ren)
{
    SDL_Surface *surface;
    surface= IMG_Load(filelocation);
    SDL_Texture *tex=SDL_CreateTextureFromSurface(ren,surface);
    return tex;
}
