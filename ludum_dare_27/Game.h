#pragma once

enum EXCEPTIONS{
	COULD_NOT_CREATE_WINDOW,
	COULD_NOT_CREATE_RENDERER,
	COULD_NOT_CREATE_GL_CONTEXT
};

enum GAME_STATE{
	RUNNING,
	CLEANING,
	LOADING
};

class Game
{
public:
	Game(void);
	~Game(void);

	void init();
	void render();
	void update();
	void handleEvents();
	void clean();
	void run();

};

