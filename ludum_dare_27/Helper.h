#pragma once

#define SIGN(v) ((v > 0) ? 1 : ((v < 0) ? -1 : 0))
#define frand() ((float)rand()/(float)RAND_MAX)

enum RESOURCE_ID {
	RC_DIRT = 1,
	RC_GRASS
};