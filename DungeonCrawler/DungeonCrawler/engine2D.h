#pragma once
#include "renderer2D.h"
#include "scene.h"

class ENGINE_2D {
public:
	RENDERER_2D* renderer;
	SCENE* scene;
	ENGINE_2D(RENDERER_2D* renderer,SCENE* scene);
	void start();
	void update();
	void stop();
};
