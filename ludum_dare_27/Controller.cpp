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