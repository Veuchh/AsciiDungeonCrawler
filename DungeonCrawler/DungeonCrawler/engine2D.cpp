#include "engine2D.h"
#include "combat.h"
#include "player_data.h"
#include "UIScript.h"

ENGINE_2D::ENGINE_2D(RENDERER_2D* renderer, SCENE* scene)
{
	this->renderer = renderer;
	this->scene = scene;
}

void ENGINE_2D::start()
{
	renderer->start();

	PLAYER_DATA* playerData = new PLAYER_DATA(100, 10);

	COMBAT* combat = new COMBAT();
	scripts.push_back(combat);
	//UI_SCRIPT* userInterface = new UI_SCRIPT();
	//scripts.push_back(userInterface);


	scriptStart();
	while (true)
	{
		scriptUpdate();
		scene->Draw();
		renderer->update();
		Sleep(150);
	}
}

void ENGINE_2D::scriptStart()
{
	for (GAME_SCRIPT* script : scripts)
	{
		script->Start();
	}
}

void ENGINE_2D::scriptUpdate()
{
	for (GAME_SCRIPT* script : scripts)
	{
		script->Update();
	}
}