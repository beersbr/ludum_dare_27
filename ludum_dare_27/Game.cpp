#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw COULD_NOT_INIT_SDL;

	//windowWidth = 1280;
	//windowHeight = 800;

	windowWidth = 1920;
	windowHeight = 1080;

	pWindow = SDL_CreateWindow("Ludum Dare 27 :: 10 Seconds", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if(!pWindow)
		throw COULD_NOT_CREATE_WINDOW;

	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	if(!pRenderer)
		throw COULD_NOT_CREATE_RENDERER;

	glContext = SDL_GL_CreateContext(pWindow);

	if(!glContext)
		throw COULD_NOT_CREATE_GL_CONTEXT;

	frameStart = 0.0f;
	frameTime = 0.0f;
	fps = 60.0f;
	framesPerSecond = 0.0f;
	totalFrames = 0;

	delayTime = 1000.0/fps;

	gamestate = RUNNING;
}

void Game::init_gl()
{
	SDL_GL_SetSwapInterval(1);

	glShadeModel(GL_SMOOTH);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_CULL_FACE);
	//glEnable(GL_MULTISAMPLE_ARB);
	//glEnable(GL_MULTISAMPLE);
	
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	GLfloat ratio = (GLfloat)windowWidth/(GLfloat)windowHeight;
	glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50.0f, ratio, 0.1f, 500.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
}

void Game::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	world->render();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	SDL_GL_SwapWindow(pWindow);
}

void Game::update()
{
	if(Controller::instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		gamestate = CLEANING;

	world->update();
}

void Game::handleEvents()
{
	Controller::instance()->resetMouseMoved();
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
			{
				gamestate = CLEANING;
				break;
			}
			case SDL_KEYDOWN:
			{
				Controller::instance()->onKeyDown(event.key.keysym.scancode);
				break;
			}
			case SDL_KEYUP:
			{
				Controller::instance()->onKeyUp(event.key.keysym.scancode);
				break;
			}
			case SDL_MOUSEMOTION:
			{
				Controller::instance()->onMouseMove(event.motion.xrel, event.motion.yrel, event.motion.x, event.motion.y);
				break;
			}
			case SDL_WINDOWEVENT:
			{
				switch(event.window.event)
				{
				case SDL_WINDOWEVENT_HIDDEN:
					Controller::instance()->showMouse();
					break;
				case SDL_WINDOWEVENT_SHOWN:
					Controller::instance()->hideMouse();
					break;
				case SDL_WINDOWEVENT_LEAVE:
					Controller::instance()->showMouse();
					break;
				case SDL_WINDOWEVENT_ENTER:
					Controller::instance()->hideMouse();
					break;
				}
				break;
			}
		}
	}
}

void Game::clean()
{
	if(world != nullptr)
		free(world);
}

void Game::run()
{
	init();
	init_gl();

	startTime = SDL_GetTicks();

	world = new World();
	world->generateMap(500, 500);

	world->player = new Player();
	((Player*)(world->player))->playerState = ISFREECAM;

	while(gamestate == RUNNING)
	{
		frameStart = SDL_GetTicks();

		handleEvents();
		update();
		render();
		
		++totalFrames;
		framesPerSecond = totalFrames/((float)SDL_GetTicks() - startTime)/1000.0;

		std::cerr << framesPerSecond << std::endl;

		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime < delayTime)
			SDL_Delay((int)(delayTime - frameTime));
	}

	clean();
}
