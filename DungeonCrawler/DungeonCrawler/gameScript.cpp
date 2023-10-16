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

	}
}
void GAME_SCRIPT::Stop()
{
	isRunning = false;
}
