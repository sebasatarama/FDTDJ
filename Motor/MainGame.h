#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "SpriteArray.h"
#include "HLSLProgram.h"
#include <chrono>
#include <thread>
using namespace std;

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int width;
	int height;
	float time;
	SDL_Window* window;
	void init();
	HLSLProgram program;
	SpriteArray sprites;
	void processInput();
	void initShaders();
	chrono::duration<int, std::milli> interval;

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

