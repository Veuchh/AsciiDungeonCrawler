#include "engine2D.h"

ENGINE_2D::ENGINE_2D(RENDERER_2D* renderer, SCENE* scene)
{
	this->renderer = renderer;
	this->scene = scene;
}

void ENGINE_2D::start()
{
	renderer->start();
	while (true)
	{
		scene->Draw();
		renderer->update();
		Sleep(500);
	}
}