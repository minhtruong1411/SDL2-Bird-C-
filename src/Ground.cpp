#include "Ground.h"
void Ground::Render(SDL_Renderer *ren)
{
   SDL_RenderCopy(ren,getTexture(),&getSrc(),&getDest());
}
void Ground::Move(Ground &ground2)
{
   xPos--;
 ground2.xPos=xPos+SCREEN_WIDTH;
setDest( xPos,SCREEN_HEIGHT-LAND_HEIGHT ,SCREEN_WIDTH,LAND_HEIGHT );
ground2.setDest( ground2.xPos,SCREEN_HEIGHT-LAND_HEIGHT ,SCREEN_WIDTH,LAND_HEIGHT );
    if (xPos <= -SCREEN_WIDTH)
    {
   xPos=0;
    }
}
