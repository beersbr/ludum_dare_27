#pragma once

#include "Vector.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);

public:
	Vector pos;
	Vector direction;
	Vector target;
};

