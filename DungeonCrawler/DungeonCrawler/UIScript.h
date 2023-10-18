#pragma once

#include "gameScript.h"
#include "scene.h"
#include "userInterface.h"

class UI_SCRIPT : public GAME_SCRIPT 
{
	USER_INTERFACE* ui;
	void Start();
	void Update();

};