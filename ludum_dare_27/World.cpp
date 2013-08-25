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

	GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f }; 
	GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f }; 
	GLfloat LightPosition[]= { 0.0f, 15.0f, 0.0f, 1.0f }; 

	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);

	player->render();

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);
		glVertex3f(0.0f, -10.0f, 0.0f);
	glEnd();


	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glColor3f(1.0f, 1.0f, 1.0f);
	//for(int z = 0; z < height-1; ++z)
	//{
	//	glBegin(GL_TRIANGLE_STRIP);
	//	for(int x = 0; x < width-1; ++x)
	//	{
	//		glVertex3f((GLfloat)x-width/2, (GLfloat)terrain[x][z], (GLfloat)z-height/2);
	//		glVertex3f((GLfloat)x-width/2, (GLfloat)terrain[x][z+1], (GLfloat)(z+1)-height/2);
	//	}
	//	glEnd();
	//}
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	std::vector<Entity*>::iterator it = entities.begin();
	for(it; it != entities.end(); ++it)
	{
		(*it)->render();
	}

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

}

void World::update()
{
	player->update(this);

	std::vector<Entity*>::iterator it = entities.begin();
	for(it; it != entities.end(); ++it)
	{

	}
}

void World::generateMap(int w, int h)
{
	width = w;
	height = h;

	// using normal form of line
	//float max_c = sqrt(w*w + h*h)/2;
	//srand(SDL_GetTicks());

	//std::vector<std::tuple<float, float>> lines;

	//for(int i = 0; i < 800; ++i)
	//{
	//	float a = rand();
	//	float c = (frand() * max_c - max_c/2);

	//	lines.push_back(std::make_tuple(a, c));
	//}

	terrain = (float**)malloc(sizeof(float)*h);
	for(int y = 0; y < height; ++y)
	{
		terrain[y] = (float*)malloc(sizeof(float)*w);
		for(int x = 0; x < width; ++x)
		{
			terrain[y][x] = 0.0f;
		}
	}

	//std::vector<std::tuple<float, float>>::iterator it = lines.begin();
	//for(it; it != lines.end(); ++it)
	//{
	//	float a = std::get<0>((*it));
	//	float b;
	//	float c = std::get<1>((*it));

	//	a = sin(a);
	//	b = cos(a);

	//	for(int y = 0; y < height; ++y)
	//	{
	//		for(int x = 0; x < width; ++x)
	//		{
	//			if(a*(x-(width/2)) + b*(y-(height/2)) - c > 0)
	//				terrain[y][x] += 0.25f;
	//			else
	//				terrain[y][x] -= 0.25f;
	//		}
	//	}
	//}

}
