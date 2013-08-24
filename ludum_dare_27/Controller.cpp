#include "Controller.h"


Controller* Controller::_instance = nullptr;

Controller* Controller::instance()
{
	if(Controller::_instance == nullptr)
		Controller::_instance = new Controller();

	return Controller::_instance;
}

Controller::Controller(void)
{
	keyStatus.clear();
	mouseDidMove = false;
	mouseSpeed = 0.03f;
}

void Controller::onKeyDown(short keyCode)
{
	keyStatus[keyCode] = true;
}

void Controller::onKeyUp(short keyCode)
{
	keyStatus[keyCode] = false;
}

void Controller::onMouseMove(int offx, int offy, int mX, int mY)
{
	mouseDidMove = true;
	offsetx = offx;
	offsety = offy;
	mousex = mX;
	mousey = mY;
}

bool Controller::isKeyDown(short keyCode)
{
	return keyStatus[keyCode];
}

int Controller::offsetX()
{
	return offsetx;
}

int Controller::offsetY()
{
	return offsety;
}

int Controller::mouseX()
{
	return mousex;
}

int Controller::mouseY()
{
	return mousey;
}

void Controller::showMouse()
{
	SDL_SetRelativeMouseMode((SDL_bool)false);
}


void Controller::hideMouse()
{
	SDL_SetRelativeMouseMode((SDL_bool)true);
}

void Controller::resetMouseMoved()
{
	mouseDidMove = false;
}

bool Controller::mouseMoved()
{
	return mouseDidMove;
}

void Controller::setMouseSpeed(float ms)
{
	mouseSpeed = ms;
}

float Controller::getMouseSpeed()
{
	return mouseSpeed;
}