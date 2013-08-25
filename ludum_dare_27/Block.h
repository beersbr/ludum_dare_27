#pragma once

#include "Helper.h"
#include "Entity.h"
#include <SDL.h>
#include <SDL_opengl.h>

class Block : public Entity
{
public:
	Block(void);
	Block(const Vector p, const Vector size);
	~Block(void);

	virtual void update(void* world);
	virtual void render();
	virtual void setColliding(bool ic);

public:
	Vector color;
};
