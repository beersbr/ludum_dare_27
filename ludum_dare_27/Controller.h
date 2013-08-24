#pragma once

#include <map>

#include <SDL.h>

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

	void showMouse();
	void hideMouse();

	void resetMouseMoved();
	bool mouseMoved();

	void setMouseSpeed(float ms);
	float getMouseSpeed();

private:
	Controller(void);

	bool mouseDidMove;

	int offsetx, offsety;
	int mousex, mousey;
	float mouseSpeed;

	std::map<short, bool> keyStatus;

	static Controller* _instance;
};