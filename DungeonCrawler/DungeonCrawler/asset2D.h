#pragma once
class ASSET_2D {
public:
	int pos_x;
	int pos_y;
	int width;
	int height;
	virtual void Draw(WORD** px)=0;
};