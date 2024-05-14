#include "Gameloop.h"
Gameloop::Gameloop()
{

    window=NULL;
    renderer=NULL;
     Gamestate=false;
  player.setSource(0,0,17,12);
     player.setDest(SCREEN_WIDTH/2-40,SCREEN_HEIGHT/2-40,BIRD_WIDTH,BIRD_HEIGHT);
//setup ground
ground1.setSource(0,0,154,56);
ground1.setDest(0,SCREEN_HEIGHT-LAND_HEIGHT ,SCREEN_WIDTH,LAND_HEIGHT );
ground2.setSource(0,0,154,56);
ground2.setDest(SCREEN_WIDTH,SCREEN_HEIGHT-LAND_HEIGHT ,SCREEN_WIDTH,LAND_HEIGHT );
ground1.xPos=0;
//set up pie
for(int i=0;i<TOTAL_PIPE;i++)
{
    upPipe[i].SetUp(i,1);
    downPipe[i].SetUp(i,0);
}
//set up MenuStart
FlappyBirdText.setSource(0,0,96,22);
FlappyBirdText.setDest(SCREEN_WIDTH/2-170,SCREEN_HEIGHT/2-100,300,50);
MenuBird.setSource(0,0,17,12);
MenuBird.setDest(SCREEN_WIDTH/2-165+310,SCREEN_HEIGHT/2-100,BIRD_WIDTH,BIRD_HEIGHT);
StartButton.setSource(0,0,40,14);
StartButton.setDest(SCREEN_WIDTH/2-100,SCREEN_HEIGHT/2+100,200,50);
GetReady.setSource(0,0,87,22);
GetReady.setDest(SCREEN_WIDTH/2-40-100,SCREEN_HEIGHT/2-40-60-44,261,66);
Hand.setSource(0,0,11,30);
Hand.setDest(SCREEN_WIDTH/2-30,SCREEN_HEIGHT/2+10,33,90);
TapTap.setSource(0,0,22,9);
TapTap.setDest(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,66,27);
//set up MenuEnd
ScorePanel.setSource(0,0,113,58);
ScorePanel.setDest(SCREEN_WIDTH/2-160,SCREEN_HEIGHT/2-150,339,174);
OkButton.setSource(0,0,40,14);
OkButton.setDest(SCREEN_WIDTH/2-80,SCREEN_HEIGHT/2-150+174+30,160,56);
}
bool Gameloop::getGameState()
{
    return Gamestate;
}
void Gameloop::Intialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("Flappy Bird",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
    if(window==NULL)
    {
        cout<<"can't create window!"<<endl;
    }
    else
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer==NULL)
        {
            cout<<"can't create renderer!"<<endl;

        }
        else
        {
            cout<<"created!"<<endl;
          Gamestate=true;
        background= TextureManager:: TexTure("Background.png",renderer);
player.CreateTexture("Bird1.png",renderer);
ground1.CreateTexture("Ground1.png",renderer);
ground2.CreateTexture("Ground1.png",renderer);
FlappyBirdText.CreateTexture("FlappyBirdText.png",renderer);
MenuBird.CreateTexture("Bird1.png",renderer);
StartButton.CreateTexture("StartButton.png",renderer);
GetReady.CreateTexture("GetReadyText.png",renderer);
Hand.CreateTexture("TutorialHand.png",renderer);
TapTap.CreateTexture("Tap.png",renderer);
ScorePanel.CreateTexture("ScorePanel.png",renderer);
OkButton.CreateTexture("OkButton.png",renderer);
for(int i=0;i<TOTAL_PIPE;i++)
{

    upPipe[i].CreateTexture("PipeUp.png",renderer);
    downPipe[i].CreateTexture("PipeDown.png",renderer);
}

	  if (Mix_Init(1) == 0)
    {
        cout << "Couldn't initialize mixer " << Mix_GetError() << '\n';
    }
    else
    {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 120) < 0)
            cout << "Error:" << Mix_GetError() << '\n';

        wingSound = Mix_LoadWAV("sfx_wing.wav");
        hitSound = Mix_LoadWAV("flappy-bird-hit-sound-101soundboards.wav");
        pointSound = Mix_LoadWAV("sfx_point.wav");
    }
	}
    }
}
void Gameloop::Event()
{
   player.GetJumpTime();
    SDL_PollEvent(&event1);
    if(event1.type == SDL_QUIT)
    {
        Gamestate=false;
    }
   if(event1.type == SDL_MOUSEBUTTONDOWN)
  {
      if(ClickStart==0&&isClickButton(StartButton))
      {

            ClickStart=1;
      }
  }

 if(!isPlaying())
 {
      if(event1.type == SDL_KEYDOWN)
      {
            if (event1.key.keysym.sym == SDLK_SPACE)
                ClickSpacetoStart=1;
      }
 }
 if(isPlaying())

   {
       if(event1.type == SDL_KEYDOWN|| event1.type == SDL_MOUSEBUTTONDOWN)
    {
           if(!isDie)
            {
                if (event1.key.keysym.sym == SDLK_SPACE||event1.button.button == SDL_BUTTON_LEFT)
             {

                 if(!player.JumpState())
                 {
                     player.Jump();
                     Mix_PlayChannel(1, wingSound, 0);
                 }
                else
                 {
                    player.Gravity();
                 }
             }

            }

    }
    else
    {
        player.Gravity();
    }
   }
if(isDie)
{
    if(event1.type == SDL_MOUSEBUTTONDOWN&&isClickButton(OkButton))
    {
       if(score>getHighScore())
       {
           saveHighScore(score);
       }
        NewGame();
    }


}
}

void Gameloop::Update()
{
player.Update(renderer);

for(int i=0;i<TOTAL_PIPE;i++)
{
    upPipe[i].Move(i,downPipe[i]);

}
 score=CountScore(score);
ground1.Move(ground2);
string s=to_string(score);
for(int i=0;i<s.size();i++)
{
    gamescore[i].Update(s[i],renderer,i);
}
string best=to_string(getHighScore());
for(int i=0;i<best.size();i++)
{
  bestScore[i].Update(best[i],renderer,i);
}
if(player.getYpos()==SCREEN_HEIGHT-LAND_HEIGHT) isDie=1;
if(isDie==0)
{
    if(detectCollision()) Mix_PlayChannel(1, hitSound, 0);
    isDie=detectCollision();
}
}
void Gameloop::Render()
{
SDL_RenderClear(renderer);
SDL_RenderCopy(renderer,background,NULL,NULL);
player.Render(renderer);

for(int i=0;i<TOTAL_PIPE;i++)
{
    upPipe[i].Render(renderer);
    downPipe[i].Render(renderer);
}
for(int i=0;i<2;i++)
{
    gamescore[i].Render(renderer);
}
ground1.Render(renderer);
ground2.Render(renderer);
SDL_RenderPresent(renderer);

}
void Gameloop::Clear()
{
    SDL_RenderClear(renderer);
}
bool Gameloop::isPlaying()
{
    return ClickSpacetoStart;
}
void Gameloop::WhenNotPlaying()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    ground1.Render(renderer);
ground2.Render(renderer);
   ground1.Move(ground2);
   FlappyBirdText.Render(renderer);
   MenuBird.Render(renderer);
 MenuBird.Update(renderer);
 StartButton.Render(renderer);
   SDL_RenderPresent(renderer);

}
bool Gameloop:: isClickButton(MenuStart buttons)
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    SDL_Rect butrect=buttons.getDest();
    int x1=butrect.x,x2=butrect.x+butrect.w;
    int y1=butrect.y,y2=butrect.y+butrect.h;
    if((x >= x1 && x <= x2 && y >= y1 && y <= y2)) return 1;
    return 0;
}
bool Gameloop::isStart()
{
    if (ClickStart==1) return 1;
    return 0;
}
void Gameloop::isNotReady()
{
     SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    ground1.Render(renderer);
ground2.Render(renderer);
 ground1.Move(ground2);
 player.Render(renderer);
 player.Update(renderer);
 GetReady.Render(renderer);
 Hand.Render(renderer);
 TapTap.Render(renderer);
   SDL_RenderPresent(renderer);
}
bool Gameloop::detectCollision()
{
    SDL_Rect BirdRect=player.getDest();
    int bX1=BirdRect.x,bX2=BirdRect.x+BIRD_WIDTH;
    int bY1=BirdRect.y,bY2=BirdRect.y+BIRD_HEIGHT;
  SDL_Rect land=ground1.getDest();

  if(bY2>=SCREEN_HEIGHT-LAND_HEIGHT) return 1;
    for(int i=0;i<TOTAL_PIPE;i++)
    {
        SDL_Rect PipeRect=downPipe[i].getDest();
            int pX1=PipeRect.x,pX2=PipeRect.x+PIPE_WIDTH;
           int pY=PipeRect.y-PIPE_SPACE;
         if(bX2>=pX1&&bX2<=pX2&&bY1<=pY)  return 1;
        if(bX1>=pX1&&bX1<=pX2&&bY1<=pY) return 1;
        PipeRect=downPipe[i].getDest();
           pY=PipeRect.y;
       if(bX2>=pX1&&bX2<=pX2&&bY2>=pY) return 1;
        if(bX1>=pX1&&bX1<=pX2&&bY2>=pY)return 1;


    }
 return 0;
}
bool Gameloop::getPlayerState()
{
    return isDie;
}
void Gameloop::EndGame()
{
SDL_RenderClear(renderer);

SDL_RenderCopy(renderer,background,NULL,NULL);
player.Render(renderer);


for(int i=0;i<TOTAL_PIPE;i++)
{
    upPipe[i].Render(renderer);
    downPipe[i].Render(renderer);
}

for(int i=0;i<2;i++)
{
    gamescore[i].setDest(300+i*23,225,21,30);
    gamescore[i].Render(renderer);
}
ground1.Render(renderer);
ground2.Render(renderer);
ScorePanel.Render(renderer);
for(int i=0;i<2;i++)
{
gamescore[i].Render(renderer);
}
for(int i=0;i<2;i++)
{
    bestScore[i].setDest(300+i*23,225+70,21,30);
    bestScore[i].Render(renderer);
}

OkButton.Render(renderer);

SDL_RenderPresent(renderer);
}
int Gameloop::CountScore(int s)
{

for(int i=0;i<TOTAL_PIPE;i++)

    {
        if(upPipe[i].getPassState()&&detectCollision()==0)
        {
        s++;
        Mix_PlayChannel(2, pointSound, 0);
        }
    }
return s;
}
void Gameloop::NewGame()
{

ClickSpacetoStart=0;
            player.setDest(SCREEN_WIDTH/2-40,SCREEN_HEIGHT/2-40,BIRD_WIDTH,BIRD_HEIGHT);
            for(int i=0;i<TOTAL_PIPE;i++)
{
    upPipe[i].SetUp(i,1);
    downPipe[i].SetUp(i,0);
}
            isDie=0;
            score=0;

}
int Gameloop::getHighScore()
{
    int best;
    ifstream file("highScore.txt");
    if(file.is_open())
    {
        file>>best;
        file.close();
    }
    return best;
}
void Gameloop::saveHighScore(int newbest)
{
     ofstream file("highScore.txt");
    if(file.is_open())
    {
        file<<newbest;
        file.close();
    }
}
