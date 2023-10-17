#include "gameScript.h"

void GAME_SCRIPT::Start()
{
	isRunning = true;
}

void GAME_SCRIPT::Run()
{
	isRunning = true;
}
void GAME_SCRIPT::Update()
{
	if (isRunning)
	{
		//Your code goes here. It will be executed for each loop.
	}
}
void GAME_SCRIPT::Stop()
{
	isRunning = false;
}
