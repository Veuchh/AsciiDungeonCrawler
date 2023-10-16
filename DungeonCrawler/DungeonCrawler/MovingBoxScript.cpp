#include "MovingBoxScript.h"

void MOVING_BOX_SCRIPT::Bind(RECTANGLE* rect)
{
	rectangle = rect;
}

void MOVING_BOX_SCRIPT::Update()
{
	if (isRunning)
	{
		if (speed_x != 0)
		{
			if (speed_x > 0)
			{
				if (rectangle->pos_x + rectangle->height >= PIXEL_HEIGHT)
				{
					speed_x = -speed_x;
				}
			}
			else {
				if (rectangle->pos_x <= 0)
				{
					speed_x = -speed_x;
				}

			}
			rectangle->pos_x += speed_x;
		}
		if (speed_y != 0)
		{
			if (speed_y > 0)
			{
				if (rectangle->pos_y + rectangle->width >= PIXEL_WIDTH)
				{
					speed_y = -speed_y;
				}
			}
			else {
				if (rectangle->pos_y <= 0)
				{
					speed_y = -speed_y;
				}

			}
			rectangle->pos_y += speed_y;
		}
		
		
	}
}