#include "PlayerShadow.h"


PlayerShadow::PlayerShadow(void)
{
	bType = RC_SHADE;
	state = ALIVE;
}

PlayerShadow::PlayerShadow(std::list<ActionState> moves)
{
	record = moves;
	bType = RC_SHADE;
	pos = moves.front().pos;

	size.x = 2.2f;
	size.z = 2.2f;
	size.y = 4.5f;

	state = ALIVE;
}

PlayerShadow::~PlayerShadow(void)
{

}

void PlayerShadow::update(void* w)
{
	World* world = (World*)w;
	
	switch(state)
	{
		case ALIVE:
		{
			if(record.size() == 0)
			{
				state = DYING;
				break;
			}

			ActionState as = record.front();
			record.pop_front();

			pos = as.pos;
			vel = as.vel;
			direction = as.dir;
	
			if(as.shoot)
			{
				world->entities.push_back(new Bullet(pos+(direction*3), direction));
			}

			break;
		}
		case DYING:
		{
			onDie();
			break;
		}
	}
}

void PlayerShadow::onDie()
{
	state = DEAD;
}

void PlayerShadow::render()
{
	glBindTexture(GL_TEXTURE_2D, Resources::instance()->textures[bType]); 

	glBegin(GL_TRIANGLES);

	// front
	glNormal3f(0, 0, 1);

	glTexCoord2f(size.x/2.0f, size.y/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0, size.y/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(size.x/2.0f, 0.0);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(0, 0, 1);

	glTexCoord2f(0.0f, size.y/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0, 0.0);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(size.x/2.0f, 0.0);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));


	// left
	glNormal3f(-1, 0, 0);

	glTexCoord2f(size.y/2.0f, size.z/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(size.y/2.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, size.z/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(-1, 0, 0);

	glTexCoord2f(0.0f, size.z/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(size.y/2.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));


	// back
	glNormal3f(0, 0, -1);

	glTexCoord2f(size.x/2.0f, size.y/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(size.x/2.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, size.y/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 0, -1);

	glTexCoord2f(0.0f, size.y/2.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(size.x/2.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));


	// right
	glNormal3f(1, 0, 0);

	glTexCoord2f(size.y/2.0f, size.z/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0f, size.z/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(size.y/2.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(1, 0, 0);

	glTexCoord2f(size.y/2.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, size.z/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));


	// bottom
	glNormal3f(0, -1, 0);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(0, -1, 0);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 1, 0);


	// top
	glTexCoord2f(0.0f, (size.z/2.0f));
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(size.x/2.0f, size.z/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 1, 0);

	glTexCoord2f(size.x/2.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(size.x/2.0f, size.z/2.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

}
