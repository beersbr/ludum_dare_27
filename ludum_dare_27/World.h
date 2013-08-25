#pragma once

#include "Helper.h"
#include "Entity.h"
#include "Vector.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>

#include <tuple>

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
	Entity* player;

	float** terrain;
	int width;
	int height;

	Vector gravity;

private:

};