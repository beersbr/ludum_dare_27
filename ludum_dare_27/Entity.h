#pragma once

#include "Vector.h"

class Entity
{
public:
	Entity(void);
	~Entity(void);

	virtual void draw() = 0;
	virtual void update() = 0;

public:
	Vector pos; // position
	Vector acc; // accelleration
	Vector vel; // velocity
	Vector size;

};

