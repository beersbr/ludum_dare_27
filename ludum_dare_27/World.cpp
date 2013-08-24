#include "World.h"

World::World(void)
{
	terrain = nullptr;
}


World::~World(void)
{
	for(int x = 0; x < width; x++)
	{
		if(terrain[x] != nullptr)
			free(terrain[x]);
	}
}

void World::render()
{
	player->render();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);
		glVertex3f(0.0f, -10.0f, 0.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	for(int z = 0; z < height-1; ++z)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for(int x = 0; x < width-1; ++x)
		{
			glVertex3f(x, 0.0f, z);
			glVertex3f(x, 0.0f, z+1);
		}
		glEnd();
	}


}

void World::update()
{
	player->update(this);
}

void World::generateMap(int w, int h)
{
	width = w;
	height = h;

	terrain = (float**)malloc(sizeof(float)*h);
	for(int y = 0; y < height; ++y)
	{
		terrain[y] = (float*)malloc(sizeof(float)*w);
		for(int x = 0; x < width; ++x)
		{
			terrain[y][x] = 0.0f;
		}
	}
}
