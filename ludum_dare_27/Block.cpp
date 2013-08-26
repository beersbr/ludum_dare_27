#include "Block.h"

Block::Block(void)
{
	bType = 0;
}

Block::Block(const Vector p, const Vector size, int type)
{
	pos = p;
	this->size = size;

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

void Block::setColliding(bool collision)
{

}