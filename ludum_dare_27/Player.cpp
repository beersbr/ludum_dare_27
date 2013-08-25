#include "Player.h"

Player::Player(void)
{
	direction.x = 0;
	direction.y = 0;
	direction.z = -1;

	pos.x = 0;
	pos.y = 10;
	pos.z = 100;

	lightPos = pos;
	lightPos.y += 0.5;

	acc = VECTOR_ZERO;
	vel = VECTOR_ZERO;

	camera.pos = pos;
	camera.direction = direction;
	camera.target = pos + direction*10;

	accSpeed = 0.05;
	friction = 0.86;

	size.x = 1.2;
	size.z = 1.2;
	size.y = 2.8;
}

Player::~Player(void)
{
}

void Player::update(void* w)
{
	World* world = (World*)w;

	switch(playerState)
	{
		case ISJUMPING:
		{
			if(Controller::instance()->isKeyPressed(SDL_SCANCODE_8))
				playerState = ISFREECAM;

			if(Controller::instance()->mouseMoved())
			{
				float offsetX = Controller::instance()->offsetX();
				float offsetY = Controller::instance()->offsetY();

				if(offsetY != 0.0)
				{ 
					Vector v = Vector(direction.x, 0, direction.z);
					v = v.toUnit();
					v = v.rotate(VECTOR_AXIS_Y, PI/2);

					direction = direction.rotate(v, SIGN(offsetY) * (Controller::instance()->getMouseSpeed() * fabs(offsetY)));
				}

				if(offsetX != 0.0)
				{
					direction = direction.rotate(VECTOR_AXIS_Y, SIGN(offsetX) * (Controller::instance()->getMouseSpeed() * fabs(offsetX)));

				}
			}

			if(Controller::instance()->isKeyDown(SDL_SCANCODE_W))
			{
				Vector v = direction.toUnit();
				v.y = 0;
				vel += v*(accSpeed/5);
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_S))
			{
				Vector v = direction.toUnit();
				v.y = 0;
				vel -= v*(accSpeed/5);
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_A))
			{
				// strafe
				Vector v = direction.toUnit();
				v.y = 0;
				v = v.rotate(VECTOR_AXIS_Y, PI/2);
				vel -= v*(accSpeed/5);

			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_D))
			{
				// strafe
				Vector v = direction.toUnit();
				v.y = 0;
				v = v.rotate(VECTOR_AXIS_Y, PI/2);
				vel += v*(accSpeed/5);
			}

			// check intersection with terrain
			if(pos.x < (world->width/2) && pos.x >= (-world->width/2)
				&& pos.z < (world->height/2) && pos.z >= (-world->height/2))
			{
				float y = world->terrain[(int)pos.x+(world->width/2)][(int)pos.z+(world->height/2)];

				if((pos.y + vel.y) <= y)
				{
					pos.y = y;
					vel.y = 0;
					playerState = ISRUNNING;
				}
				else
					vel += world->gravity;
			}
			else
				vel += world->gravity;

			break;
		}
		case ISRUNNING:
		{
			if(Controller::instance()->isKeyPressed(SDL_SCANCODE_8))
				playerState = ISFREECAM;

			if(Controller::instance()->mouseMoved())
			{
				float offsetX = Controller::instance()->offsetX();
				float offsetY = Controller::instance()->offsetY();

				if(offsetY != 0.0)
				{ 
					Vector v = Vector(direction.x, 0, direction.z);
					v = v.toUnit();
					v = v.rotate(VECTOR_AXIS_Y, PI/2);

					direction = direction.rotate(v, SIGN(offsetY) * (Controller::instance()->getMouseSpeed() * fabs(offsetY)));
				}

				if(offsetX != 0.0)
				{
					direction = direction.rotate(VECTOR_AXIS_Y, SIGN(offsetX) * (Controller::instance()->getMouseSpeed() * fabs(offsetX)));

				}
			}

			if(Controller::instance()->isKeyDown(SDL_SCANCODE_W))
			{
				Vector v = direction.toUnit();
				v.y = 0;
				vel += v*accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_S))
			{
				Vector v = direction.toUnit();
				v.y = 0;
				vel -= v*accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_A))
			{
				// strafe
				Vector v = direction.toUnit();
				v.y = 0;
				v = v.rotate(VECTOR_AXIS_Y, PI/2);
				vel -= v*accSpeed;

			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_D))
			{
				// strafe
				Vector v = direction.toUnit();
				v.y = 0;
				v = v.rotate(VECTOR_AXIS_Y, PI/2);
				vel += v*accSpeed;
			}

			if(Controller::instance()->isKeyDown(SDL_SCANCODE_SPACE))
			{
				vel.y += 0.5;
				playerState = ISJUMPING;
			}

			// check intersection with terrain
			if(pos.x < (world->width/2) && pos.x >= (-world->width/2)
				&& pos.z < (world->height/2) && pos.z >= (-world->height/2))
			{
				float y = world->terrain[(int)pos.x+(world->width/2)][(int)pos.z+(world->height/2)];
				if((pos.y + vel.y) < y)
				{
					pos.y = y;
					vel.y = 0;
					playerState = ISRUNNING;
				}
				else
					vel += world->gravity;

			}
			else
				vel += world->gravity;

			vel.x *= friction;
			vel.z *= friction;

			break;
		}
		case ISFREECAM:
		{
			if(Controller::instance()->isKeyPressed(SDL_SCANCODE_9))
				playerState = ISJUMPING;


			if(Controller::instance()->mouseMoved())
			{
				float offsetX = Controller::instance()->offsetX();
				float offsetY = Controller::instance()->offsetY();

				if(offsetY != 0.0)
				{ 
					Vector v = Vector(direction.x, 0, direction.z);
					v = v.toUnit();
					v = v.rotate(VECTOR_AXIS_Y, PI/2);

					direction = direction.rotate(v, SIGN(offsetY) * (Controller::instance()->getMouseSpeed() * fabs(offsetY)));
				}

				if(offsetX != 0.0)
				{
					direction = direction.rotate(VECTOR_AXIS_Y, SIGN(offsetX) * (Controller::instance()->getMouseSpeed() * fabs(offsetX)));

				}
			}

			if(Controller::instance()->isKeyDown(SDL_SCANCODE_W))
			{
				Vector v = Vector(direction);
				v.toUnit();
				
				vel += v*accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_S))
			{
				Vector v = Vector(direction);
				v.toUnit();
				
				vel -= v*accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_A))
			{
				Vector v = Vector(direction.x, 0, direction.z);
				v = v.toUnit();
				v = v.rotate(VECTOR_AXIS_Y, PI/2);

				vel -= (v*accSpeed);
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_D))
			{
				Vector v = Vector(direction.x, 0, direction.z);
				v = v.toUnit();
				v = v.rotate(VECTOR_AXIS_Y, PI/2);

				vel += (v*accSpeed);
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_SPACE))
			{
				vel.y += accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_LSHIFT))
			{
				vel.y -= accSpeed;
			}

			vel *= friction;

			break;
		}
	}

	pos += vel;

	//check collision
	// TODO: hash bucket the entities
	std::vector<Entity*>::iterator it = world->entities.begin();
	for(it; it != world->entities.end(); ++it)
	{
		bool top = false;

		// TODO: make sure gravity is always working....

		if(Entity::colliding(this, *it))
		{
			// TODO: collision is happening...
			((Block*)(*it))->setColliding(true);

			Vector sz = Vector(size.x/2 + (*it)->size.x/2,
								size.y/2 + (*it)->size.y/2,
								size.z/2 + (*it)->size.z/2);

			Vector dist = this->pos - (*it)->pos;
			Vector d = dist;
			
			Vector non_dist = Vector((fabs(dist.x) - sz.x), (fabs(dist.y) - sz.y), (fabs(dist.z) - sz.z));
			Vector abs_dist = Vector(fabs(fabs(dist.x) - sz.x), fabs(fabs(dist.y) - sz.y), fabs(fabs(dist.z) - sz.z));
			
			if(abs_dist.x < abs_dist.y && abs_dist.x != 0.0 && abs_dist.x < abs_dist.z)
			{
				dist = Vector(abs_dist.x*-1, 0, 0);
				pos += dist*(SIGN(d.x)*-1);
				vel.x = 0;
			}
			if(abs_dist.y < abs_dist.x && abs_dist.y < abs_dist.z)
			{
				dist = Vector(0, abs_dist.y*-1, 0);
				pos += dist*(SIGN(d.y)*-1);
				vel.y = 0;

				if(SIGN(d.y) > 0)
				{
					playerState = ISRUNNING;
				}
			}
			if(abs_dist.z < abs_dist.y && abs_dist.z < abs_dist.x)
			{
				dist = Vector(0, 0, abs_dist.z*-1);
				pos += dist*(SIGN(d.z)*-1);
				vel.z = 0;
			}

		}
		else
		{
			((Block*)(*it))->setColliding(false);
		}
	}

	camera.pos = pos;
	camera.pos.y += 2.3f;
	camera.direction = direction;
	camera.target = camera.pos + camera.direction*10; // pos - camera.direction*10;
}

void Player::render()
{
	camera.update();
}
