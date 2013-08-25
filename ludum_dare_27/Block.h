#pragma once

#include "Helper.h"
#include "Entity.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <glut.h>
#include <gl/GL.h>

#include "Resources.h"

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
