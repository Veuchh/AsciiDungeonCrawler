#include "asset2D.h"


ASSET_2D::ASSET_2D(RENDERER_2D* renderer) : NODE_2D(renderer) {}

int ASSET_2D::GetOffsetY()
{
	switch (anchor)
	{
	case ANCHOR_TYPE::ANCHOR_TOP_LEFT:
		return 0;
		break;
	case ANCHOR_TYPE::ANCHOR_CENTERED:
		return -(width >> 1);
		break;
	case ANCHOR_TYPE::ANCHOR_TOP:
		return -(width >> 1);
		break;
	case ANCHOR_TYPE::ANCHOR_BOTTOM:
		return -(width >> 1);
		break;
	case ANCHOR_TYPE::ANCHOR_RIGHT:
		return -width;
		break;
	case ANCHOR_TYPE::ANCHOR_LEFT:
		return 0;
		break;
	default:
		break;
	}
	return 0;
}

int ASSET_2D::GetOffsetX()
{
	switch (anchor)
	{
	case ANCHOR_TYPE::ANCHOR_TOP_LEFT:
		return 0;
		break;
	case ANCHOR_TYPE::ANCHOR_CENTERED:
		return - (height >> 1);
		break;
	case ANCHOR_TYPE::ANCHOR_TOP:
		return -(height >> 1);
		break;
	case ANCHOR_TYPE::ANCHOR_BOTTOM:
		return -height;
		break;
	case ANCHOR_TYPE::ANCHOR_RIGHT:
		return -(height >> 1);
		break;
	case ANCHOR_TYPE::ANCHOR_LEFT:
		return -(height >> 1);
		break;
	default:
		break;
	}
	return 0;
}

void ASSET_2D::SetPosition(SCREEN_POSITION pos)
{
	switch (pos)
	{
	case SCREEN_CENTER:
		anchor = ANCHOR_CENTERED;
		pos_x = PIXEL_HEIGHT >> 1;
		pos_y = PIXEL_WIDTH >> 1;
		break;
	case SCREEN_LEFT:
		anchor = ANCHOR_LEFT;
		pos_x = PIXEL_HEIGHT >> 1;
		pos_y = 0;
		break;
	case SCREEN_RIGHT:
		anchor = ANCHOR_RIGHT;
		pos_x = PIXEL_HEIGHT >> 1;
		pos_y = PIXEL_WIDTH;
		break;
	case SCREEN_TOP:
		anchor = ANCHOR_TOP;
		pos_x = 0;
		pos_y = PIXEL_WIDTH >> 1;
		break;
	case SCREEN_BOTTOM:
		anchor = ANCHOR_BOTTOM;
		pos_x = PIXEL_HEIGHT;
		pos_y = PIXEL_WIDTH >> 1;
		break;
	default:
		break;
	}
}