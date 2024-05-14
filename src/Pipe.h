#pragma once
#include "Object.h"

static int  upPipeHeight[TOTAL_PIPE];
static int downPipeHeight[TOTAL_PIPE];
static int xpos[TOTAL_PIPE];

class Pipe:public Object
{
private:

bool isPass;

public:
 void Render(SDL_Renderer *ren);
void SetUp(int i,bool isUp);
int getXpos(int i);
void Move(int i,Pipe &down);
bool getPassState();



};
