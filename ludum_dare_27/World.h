#pragma once

#include "Entity.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>

class World
{
public:
	World(void);
	~World(void);

	void render();
	void update();

	void generateMap(int w, int h);

public:
	std::vector<Entity*> entities;

	float** terrain;
	int width;
	int height;
};

