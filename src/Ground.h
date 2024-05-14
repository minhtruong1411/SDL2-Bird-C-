#pragma once
#include "Object.h"

class Ground:public Object
{
private:

public:
            void Render(SDL_Renderer *ren);
void Move(Ground &other);
};
