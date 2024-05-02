#pragma once

#ifndef SYSTEM
#define SYSTEM

#include "MainHeader.h"

class cube
{
	uint8_t alfa, red, green, blue;
};

class actor;

typedef uint32_t indexActor;

const indexActor nullIndex = 0;

class grid
{
private:
	grid* p_self;
	static const uint32_t SIZE_X = 50;
	static const uint32_t SIZE_Y = 50;
	static const uint32_t SIZE_Z = 50;
	indexActor massive[SIZE_Z][SIZE_Y][SIZE_X];
public:
	class iterator
	{
		uint32_t X, Y, Z;
	};
};


#endif // !SYSTEM

