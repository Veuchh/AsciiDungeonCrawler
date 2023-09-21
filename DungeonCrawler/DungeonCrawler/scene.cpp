#include "scene.h"

SCENE::SCENE(RENDERER_2D* renderer)
{
	this->renderer = renderer;
	this->assets = new ASSET_2D*[NB_LAYER];
}

void SCENE::display()
{
	for(int l = 0; l < NB_LAYER; l++)
	{
		if (assets[l] != NULL)
		{
			//assets[l]->Draw();
		}
	}
}