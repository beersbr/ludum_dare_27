#include "Block.h"

Block::Block(void)
{
}

Block::Block(const Vector p, const Vector size)
{
	pos = p;
	this->size = size;

	color.x = 0.3f;
	color.y = 0.3f;
	color.z = 0.8f;
}

Block::~Block(void)
{
}

void Block::update(void* world)
{

}

void Block::render()
{
	glBegin(GL_TRIANGLES);
	glColor3f(color.x, color.y, color.z);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glEnd();
}

void Block::setColliding(bool collision)
{
	if(collision)
		color = Vector(1.0f, 1.0f, 1.0f);
	else
		color = Vector(0.3f, 0.3f, 0.8f);
}