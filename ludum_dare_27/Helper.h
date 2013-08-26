#pragma once

#include "Vector.h"

#define SIGN(v) ((v > 0) ? 1 : ((v < 0) ? -1 : 0))
#define frand() ((float)rand()/(float)RAND_MAX)

enum RESOURCE_ID {
	RC_DIRT = 1,
	RC_GRASS,
	RC_SHADE,
	RC_ENEMY
};

enum GAME_OBJECT_STATES {
	ALIVE,
	DYING,
	DEAD
};

struct ActionState
{
	double time;
	Vector pos;
	Vector dir;
	Vector vel;
	bool shoot;

};