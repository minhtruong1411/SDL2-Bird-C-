#pragma once
#include<SDL2/SDL.h>
#include "TextureManager.h"
#include "stats.h"
class Object
{
private:
    SDL_Rect src,dest;
    SDL_Texture *Tex;
public:
int xPos,yPos;
Object();
void CreateTexture (const char* address,SDL_Renderer*ren);
void Render(SDL_Renderer *ren);
SDL_Texture* getTexture();
SDL_Rect &getSrc();
SDL_Rect &getDest();
void setSource(int x,int y,int w, int h);
void setDest(int x,int y,int w, int h);
double getYpos();
double getXpos();
double getWitdh();
double getHeight();
};
