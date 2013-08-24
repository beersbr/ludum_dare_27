#pragma once

#include <map>

class Controller
{
public:
	static Controller* instance();
	
	void onKeyDown(short keyCode);
	void onKeyUp(short keyCode);
	void onMouseMove(int offX, int offY, int mX, int mY);

	bool isKeyDown(short keyCode);

	int offsetX();
	int offsetY();
	int mouseX();
	int mouseY();

private:
	Controller(void);

	int offsetx, offsety;
	int mousex, mousey;

	std::map<short, bool> keyStatus;

	static Controller* _instance;
};