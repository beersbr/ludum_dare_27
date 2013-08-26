#pragma once

#include <SDL_opengl.h>
#include "entity.h"
#include "World.h"


class Bullet :
	public Entity
{
public:
	Bullet(void);
	Bullet(Vector pos, Vector dir);
	~Bullet(void);

	virtual void update(void* world);
	virtual void render();
	virtual void onDie();

	void setSpeed(float s);

public:
	Vector direction;

	float speed;

};

