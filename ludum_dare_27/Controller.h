#pragma once

#include <map>

class Controller
{
public:
	static Controller* instance();
	
	void onKeyDown(short keyCode);
	void onKeyUp(short keyCode);

	bool isKeyDown(short keyCode);

private:
	Controller(void);

	std::map<short, bool> keyStatus;

	static Controller* _instance;
};