#include "Gameloop.h"
Gameloop *g=new Gameloop();
const short int FPS = 100;
const short int frameDelay = 1000 / FPS;
int main(int argc,char** argv)
{
      Uint32 frameStart;
    short int frameTime;
    g->Intialize();
    while(g->getGameState())
    {
      frameStart = SDL_GetTicks();


if(g->isStart()==0)
   {
   g->Event();
   g->WhenNotPlaying();
   }
else if(g->isStart()&&g->isPlaying()==0)
       {
           g->Event();
           g->isNotReady();

       }
      else if(g->isStart()&&g->isPlaying())
       {
if(g->getPlayerState()==0)
{g->Render();
g->Event();
g->Update();
}
else
{g->EndGame();
g->Event();
}
     }



  frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

g->Clear();
return 0;
}
