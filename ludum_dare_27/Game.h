#pragma once

#include "World.h"
#include "Controller.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <glut.h>
#include <assert.h>

enum EXCEPTIONS{
	COULD_NOT_INIT_SDL,
	COULD_NOT_CREATE_WINDOW,
	COULD_NOT_CREATE_RENDERER,
	COULD_NOT_CREATE_GL_CONTEXT
};

enum GAME_STATE{
	RUNNING,
	CLEANING,
	LOADING,
	PAUSED
};

class Game
{
public:
	Game(void);
	~Game(void);

	void init();
	void init_gl();
	void render();
	void update();
	void handleEvents();
	void clean();
	void run();

public:
	GAME_STATE gamestate;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_GLContext glContext;

	int windowWidth;
	int windowHeight;

private:
	void showMouse();
	void hideMouse();

private:
	float mouseSpeed;
	float startTime;
	float frameStart;
	float frameTime;
	float fps;
	float framesPerSecond;
	float totalFrames;
	float delayTime;

	World* world;
	Controller* controller;

	SDL_Event event;

};

