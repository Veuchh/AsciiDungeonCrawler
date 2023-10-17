#include "scene.h"

SCENE::SCENE(RENDERER_2D* renderer) : NODE_2D(renderer) {}
SCENE* SCENE::Instance;


void SCENE::Draw() {
	renderer->fill(backgroundColor);
	NODE_2D::Draw();
}