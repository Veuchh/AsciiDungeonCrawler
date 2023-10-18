#include "UIScript.h"

void UI_SCRIPT::Start()
{
	ui = new USER_INTERFACE(RENDERER_2D::Instance);
	SCENE::Instance->addChildNode(ui);
}

void UI_SCRIPT::Update()
{
	ui->enemy_healthBar->value = ui->enemy_healthBar->value - 1;
}