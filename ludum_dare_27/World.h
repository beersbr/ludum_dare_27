#pragma once

#include "Helper.h"
#include "Entity.h"
#include "Vector.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>
#include <list>

#include <tuple>

class World
{
public:
	World(void);
	~World(void);

	void render();
	void update();

	void generateMap(int w, int h);

	void onDie(Entity* e);

public:
	std::list<Entity*> entities;
	Entity* player;

	float** terrain;
	int width;
	int height;

	Vector gravity;

private:

};