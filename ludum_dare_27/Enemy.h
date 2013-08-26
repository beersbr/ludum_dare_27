#pragma once

#include "entity.h"
#include "Resources.h"
#include "Helper.h"

#include <glut.h>


class Enemy :
	public Entity
{
public:
	Enemy(void);
	Enemy(Vector p);
	~Enemy(void);

	virtual void update(void* w);
	virtual void render();
	virtual void onDie();

public:
	int bType;
	int hp;
};

