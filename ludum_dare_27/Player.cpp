#include "Player.h"

Player::Player(void)
{
	direction.x = 0;
	direction.y = 0;
	direction.z = -1;

	pos.x = 0;
	pos.y = 10;
	pos.z = 100;

	acc = VECTOR_ZERO;
	vel = VECTOR_ZERO;

	camera.pos = pos;
	camera.direction = direction;
	camera.target = pos + direction*10;

	accSpeed = 0.05;
	friction = 0.85;
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
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_F))
				playerState = ISFREECAM;

			if(Controller::instance()->isKeyDown(SDL_SCANCODE_W))
			{
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_S))
			{
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_A))
			{
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_D))
			{
			}

			break;
		}
		case ISRUNNING:
		{
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_F))
				playerState = ISFREECAM;

			if(Controller::instance()->isKeyDown(SDL_SCANCODE_W))
			{
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_S))
			{
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_A))
			{
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_D))
			{
			}
			break;
		}
		case ISFREECAM:
		{
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
				
				acc += v*accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_S))
			{
				Vector v = Vector(direction);
				v.toUnit();
				
				acc -= v*accSpeed;
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_A))
			{
				Vector v = Vector(direction.x, 0, direction.z);
				v = v.toUnit();
				v = v.rotate(VECTOR_AXIS_Y, PI/2);

				acc -= (v*accSpeed);
			}
			if(Controller::instance()->isKeyDown(SDL_SCANCODE_D))
			{
				Vector v = Vector(direction.x, 0, direction.z);
				v = v.toUnit();
				v = v.rotate(VECTOR_AXIS_Y, PI/2);

				acc += (v*accSpeed);
			}
			break;
		}
	}

	vel += acc;
	acc *= friction;
	vel *= friction;

	pos += vel;

	camera.pos = pos;
	camera.direction = direction;
	camera.target = pos + direction*10; // pos - camera.direction*10;
}

void Player::render()
{
	camera.update();
}


