    #include "Score.h"
void Score::Render(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren,getTexture(),&getSrc(),&getDest());
}
void Score::Update(char score,SDL_Renderer *ren,int i)
{
   setSource(0,0,7,10);


      int number=score-'0';
      if(number==0)
      {
          CreateTexture("Zero.png",ren);
      }
      if(number==1)
      {
          CreateTexture("One.png",ren);
      }
      if(number==2)
      {
          CreateTexture("Two.png",ren);
      }
      if(number==3)
      {
          CreateTexture("Three.png",ren);
      }
      if(number==4)
      {
          CreateTexture("Four.png",ren);
      }
      if(number==5)
      {
          CreateTexture("Five.png",ren);
      }
      if(number==6)
      {
          CreateTexture("Six.png",ren);
      }
      if(number==7)
      {
          CreateTexture("Seven.png",ren);
      }
      if(number==8)
      {
          CreateTexture("Eight.png",ren);
      }
      if(number==9)
      {
          CreateTexture("Nine.png",ren);
      }

     setDest(SCREEN_WIDTH/2-21+(23*i),50,21,30);


}
