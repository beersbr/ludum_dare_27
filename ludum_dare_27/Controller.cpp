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

bool Controller::isKeyDown(short keyCode)
{
	return keyStatus[keyCode];
}