#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"

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
	void processInput();
	Sprite sprite;
	Sprite sprite2;

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

