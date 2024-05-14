#include "Bird.h"
void Bird::Render(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren,getTexture(),&getSrc(),&getDest());
}
void Bird::Update(SDL_Renderer *ren)
{
if(flapping==0) CreateTexture("Bird1.png",ren);
 flapping++;

 if(flapping==6)  CreateTexture("Bird2.png",ren);
 if(flapping==12)
 {CreateTexture("Bird3.png",ren);
 flapping=0;
 }
}
void Bird::Gravity()
{
    if(JumpState())
   {
       accelerator1=accelerator1+0.025;
   accelerator2=accelerator2+0.05;
    jumpHeight=jumpHeight+gravity+accelerator1;
    yPos=getYpos()+gravity+accelerator1+accelerator2+jumpHeight;
    setDest(getXpos(),yPos,BIRD_WIDTH,BIRD_HEIGHT);
    if(jumpHeight>0)
    {
        inJump=false;
        jumpHeight=-6.5;

    }
   }
else
{
     accelerator1=accelerator1+0.025;
    accelerator2=accelerator2+0.05;
       yPos=getYpos()+gravity+accelerator1+accelerator2;
      setDest(getXpos(),yPos,BIRD_WIDTH,BIRD_HEIGHT);
}
}

void Bird::GetJumpTime()
{
    jumpTimer=SDL_GetTicks();
}
void Bird::Jump()
{
    if(jumpTimer-lastJump>30)
    {
        accelerator1=0;
        accelerator2=0;
        inJump=true;
        lastJump=jumpTimer;
    }
    else
    {
        Gravity();
    }
}
bool Bird::JumpState()
{
    return inJump;
}

