#include "Player.h"


Player::Player(void)
{
}


Player::~Player(void)
{
}

void Player::update()
{
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
}

void Player::draw()
{
}
