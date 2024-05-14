#pragma once
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "TextureManager.h"
#include "Bird.h"
#include "Object.h"
#include "Ground.h"
#include "Pipe.h"
#include "stats.h"
#include "Button.h"
#include "MenuStart.h"
#include "Score.h"

using namespace std;
class Gameloop
{
private:

    bool Gamestate;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event1;
SDL_Texture *background;
Bird player;
bool ClickSpacetoStart=0;
bool ClickStart=0;
bool isDie=0;
Ground ground1,ground2;
Pipe upPipe[TOTAL_PIPE];
Pipe downPipe[TOTAL_PIPE];
Score gamescore[5];
Score bestScore[5];

// Menu Start
MenuStart StartButton;
MenuStart TapTap;
MenuStart FlappyBirdText;
Bird MenuBird;
MenuStart GetReady;
MenuStart Hand;
// GameOver
MenuStart ScorePanel;
MenuStart OkButton;
//sound
  Mix_Chunk *wingSound, *hitSound, *pointSound;
public:
    Gameloop();
   bool getGameState();
    void Intialize();
    void Event();
    void Render();
    void Clear();
    void Update();
    bool isPlaying();
    void WhenNotPlaying();
    bool isClickButton(MenuStart buttons);
    bool isStart();
    void isNotReady();
    bool detectCollision();
  bool getPlayerState();
  void EndGame();
int CountScore(int s);
void NewGame();
int getHighScore();
void saveHighScore(int newbest);
};
