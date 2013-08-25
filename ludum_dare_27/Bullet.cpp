#include "Bullet.h"

Bullet::Bullet(void)
{
	speed = 0.6;
}

Bullet::~Bullet()
{
}

Bullet::Bullet(Vector pos, Vector dir)
{
	direction = dir.toUnit();
	this->pos = pos;

	size.x = 0.2;
	size.y = 0.2;
	size.z = 0.2;

	speed = 0.6;
}

void Bullet::update(void* world)
{
	vel += direction * speed;
	pos += vel;

	// CHECK COLLSISION;
}

void Bullet::render()
{
	glBegin(GL_TRIANGLES);

	// front
	glNormal3f(0, 0, 1);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(0, 0, 1);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(-1, 0, 0);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(-1, 0, 0);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 0, -1);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 0, -1);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(1, 0, 0);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(1, 0, 0);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, -1, 0);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(0, -1, 0);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 1, 0);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 1, 0);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glEnd();
}

void Bullet::setSpeed(float s)
{
	speed = s;
}