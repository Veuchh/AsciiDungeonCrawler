#pragma once
#include <stdio.h>
#include <windows.h>

class CONSOLE_BUFFER
{
public:
	CHAR_INFO** buffer;
	int size_x;

};