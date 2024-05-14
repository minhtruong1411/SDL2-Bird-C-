#pragma once
#include "Object.h"
static int flapping=0;
class Bird:public Object
{
private:

    double gravity=0.2;
    double accelerator1=0;
    double accelerator2=0;
    bool inJump=false;
    double jumpHeight=-6.5;
    double jumpTimer;
    double lastJump=0;
public:
        void Render(SDL_Renderer *ren);
void Update(SDL_Renderer *ren);
void Gravity();
void GetJumpTime();
void Jump();
bool JumpState();

};
