#pragma once
#include "renderer2D.h"
#include "scene.h"
#include "gameScript.h"

class ENGINE_2D {
public:
	RENDERER_2D* renderer;
	SCENE* scene;
	std::list<GAME_SCRIPT*> scripts;
	ENGINE_2D(RENDERER_2D* renderer,SCENE* scene);
	void start();
	void scriptStart();
	void update();
	void scriptUpdate();
	void stop();
};
