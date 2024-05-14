#pragma once
#include "Object.h"

class Score:public Object
{
private:

public:
    void Update(char score,SDL_Renderer *ren,int i);
void Render(SDL_Renderer *ren);
};
