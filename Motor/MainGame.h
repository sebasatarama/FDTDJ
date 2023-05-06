#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "HLSLProgram.h"

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int width;
	int height;
	SDL_Window* window;
	void init();
	HLSLProgram program;
	Sprite sprite;
	Sprite sprite2;
	void processInput();
	void initShaders();

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

