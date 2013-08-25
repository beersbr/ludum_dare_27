#include "Block.h"

Block::Block(void)
{
	bType = 0;
}

Block::Block(const Vector p, const Vector size, int type)
{
	pos = p;
	this->size = size;

	color.x = 0.3f;
	color.y = 0.3f;
	color.z = 0.8f;

	bType = type;
}

Block::~Block(void)
{
}

void Block::update(void* world)
{

}

void Block::render()
{
	glBindTexture(GL_TEXTURE_2D, Resources::instance()->textures[bType]); 

	glBegin(GL_TRIANGLES);

	// front
	glNormal3f(0, 0, 1);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0, 1.0);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(1.0, 0.0);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(0, 0, 1);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0, 0.0);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(1.0, 0.0);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));


	glNormal3f(-1, 0, 0);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));

	glNormal3f(-1, 0, 0);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 0, -1);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 0, -1);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y - (size.y/2), pos.z - (size.z/2));

	glNormal3f(1, 0, 0);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(1, 0, 0);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x + (size.x/2), pos.y - (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
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

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));

	glNormal3f(0, 1, 0);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(pos.x - (size.x/2), pos.y + (size.y/2), pos.z - (size.z/2));
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(pos.x + (size.x/2), pos.y + (size.y/2), pos.z + (size.z/2));
	
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);

	
}

void Block::setColliding(bool collision)
{
	if(collision)
		color = Vector(1.0f, 1.0f, 1.0f);
	else
		color = Vector(0.3f, 0.3f, 0.8f);
}