#pragma once

#include "Vector.h"

class Entity
{
public:
	Entity(void);
	virtual ~Entity(void);

	virtual void update(void* someData) = 0;
	virtual void render() = 0;

	static bool colliding(Entity* a, Entity* b);

	virtual void setColliding(bool ic);

public:
	Vector pos; // position
	Vector acc; // accelleration
	Vector vel; // velocity
	Vector size;

};