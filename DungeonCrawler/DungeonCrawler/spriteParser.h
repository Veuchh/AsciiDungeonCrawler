#pragma once

#include "spriteData.h"
#include <string>

using namespace std;

class SPRITE_PARSER
{
public:
	static SPRITE_DATA* ParseSprite(string spriteName);
};

