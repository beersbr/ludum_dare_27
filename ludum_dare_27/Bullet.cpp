#include "Bullet.h"

Bullet::Bullet(void)
{
	speed = 0.4;
	state = ALIVE;
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

	speed = 0.45;
	state = ALIVE;
	vel = direction * speed;
}

void Bullet::update(void* w)
{
	World* world = (World*)w;

	int size = world->entities.size();

	switch(state)
	{
		case ALIVE:
		{
			pos += vel;

			std::list<Entity*>::iterator it = world->entities.begin();
			for(it; it != world->entities.end(); it++)
			{
				if(this == *it) 
					continue;

				if(pos.x < -500 || pos.x > 500)
					state = DYING;

				if(pos.y < -500 || pos.y > 500)
					state = DYING;

				if(pos.z < -500 || pos.z > 500)
					state = DYING;

				if(Entity::colliding(this, (*it)))
				{
					state = DYING;
					pos -= vel;
					break;
				}
			}
			break;
		}
		case DYING:
		{
			onDie();
			break;
		}
	}


	

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

void Bullet::onDie()
{
	state = DEAD;
}