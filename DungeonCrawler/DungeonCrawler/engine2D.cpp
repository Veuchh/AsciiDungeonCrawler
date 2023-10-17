#include "engine2D.h"
#include "combat.h"

ENGINE_2D::ENGINE_2D(RENDERER_2D* renderer, SCENE* scene)
{
	this->renderer = renderer;
	this->scene = scene;
}

void ENGINE_2D::start()
{
	scriptStart();
	renderer->start();

	COMBAT* combat = new COMBAT();
	scripts.push_back(combat);
	
	while (true)
	{
		scriptUpdate();
		scene->Draw();
		renderer->update();
		Sleep(500);
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