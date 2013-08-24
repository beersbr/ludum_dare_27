#pragma once

#include "Entity.h"
#include "Camera.h"
#include "Controller.h"

#include <SDL.h>

class Player : public Entity
{
public:
	Player(void);
	~Player(void);

	virtual void update();
	virtual void draw();

public:
	Camera camera;
	Vector direction;
};

