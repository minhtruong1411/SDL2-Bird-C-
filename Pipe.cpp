#include "Pipe.h"
void Pipe::Render(SDL_Renderer *ren)
{
   SDL_RenderCopy(ren,getTexture(),&getSrc(),&getDest());
}
void Pipe::SetUp(int i,bool isUp)
{
int distance=0;
setSource(0,0,26,120);
if(isUp)  upPipeHeight[i]=rand() % (650 - 140 -250)+70 ;
 downPipeHeight[i]=SCREEN_HEIGHT-LAND_HEIGHT-(upPipeHeight[i]+PIPE_SPACE);
 if(upPipeHeight[i]>downPipeHeight[i]) downPipeHeight[i]=upPipeHeight[i];
 else
 {
      distance=downPipeHeight[i]-upPipeHeight[i];
    upPipeHeight[i]=downPipeHeight[i];
 }
 xpos[i]=SCREEN_WIDTH+i*PIPE_DISTANCE+50;

if(isUp) setDest(xpos[i],0-distance,PIPE_WIDTH,upPipeHeight[i]);
else setDest(xpos[i],upPipeHeight[i]+PIPE_SPACE,PIPE_WIDTH,downPipeHeight[i]);
}
int Pipe::getXpos(int i)
{
    return xpos[i];
}
void Pipe::Move(int i,Pipe &down) {
    xpos[i]--;
int distance=0;
if(xpos[i]+PIPE_WIDTH==SCREEN_WIDTH/2-40-1) isPass=1;
else isPass=0;
if(xpos[i]<-PIPE_WIDTH)
{

    xpos[i]=SCREEN_WIDTH;
upPipeHeight[i]=rand() % (650 - 140 - 250)+70;
 downPipeHeight[i]=SCREEN_HEIGHT-LAND_HEIGHT-(upPipeHeight[i]+PIPE_SPACE);
if(upPipeHeight[i]>downPipeHeight[i]) downPipeHeight[i]=upPipeHeight[i];

}
  setDest(xpos[i],0-abs(downPipeHeight[i]-upPipeHeight[i]),PIPE_WIDTH,upPipeHeight[i]+abs(downPipeHeight[i]-upPipeHeight[i]));
down.setDest(xpos[i],upPipeHeight[i]+PIPE_SPACE,PIPE_WIDTH,downPipeHeight[i]);

}
bool Pipe::getPassState()
{
    return isPass;
}
