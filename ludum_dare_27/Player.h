#pragma once

#include "Helper.h"
#include "Entity.h"
#include "Camera.h"
#include "Controller.h"
#include "World.h"
#include "Block.h"
#include "Bullet.h"
#include "PlayerShadow.h"

#include <SDL.h>
#include <stack>

enum PLAYER_STATE {
	ISWALKING,
	ISJUMPING,
	ISRUNNING,
	ISFREECAM,
	ISFALLING
};

class Player : public Entity
{
public:
	Player(void);
	~Player(void);

	virtual void update(void* world);
	virtual void render();

public:
	PLAYER_STATE playerState;

	Camera camera;
	Vector jumpVector;
	Vector force;
	Vector lightPos;

	float accSpeed;
	float friction;

	float mass;

	std::list<ActionState> record;

};
