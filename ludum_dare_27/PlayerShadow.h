#pragma once
#include "entity.h"
#include "World.h"
#include "Resources.h"
#include "Bullet.h"

#include <stack>

class PlayerShadow :
	public Entity
{
public:
	PlayerShadow(void);
	PlayerShadow(std::list<ActionState> moves);
	~PlayerShadow(void);

	virtual void update(void* w);
	virtual void render();
	virtual void onDie();

public:
	std::list<ActionState> record;
	int bType;
};

