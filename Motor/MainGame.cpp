#include "MainGame.h"
#include <iostream>
#include "Error.h"
using namespace std;

MainGame::MainGame() {
	window = nullptr;
	width = 800;
	time = 0;
	height = 600;
	gameState = GameState::PLAY;
}

MainGame::~MainGame() {

}
void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				//cout << event.motion.x << " , " << event.motion.y << endl;
				break;
		}
	}
}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			width, height, SDL_WINDOW_OPENGL);
	
	if (window == nullptr) {
		fatalError("SDL not initialized");
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Glew not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.02;
	sprite.draw();
	sprite2.draw();
	program.unuse();
	//si tengo elementos actualizo
	SDL_GL_SwapWindow(window);
}

void MainGame::run() {
	init();
	sprite.init(-1, -1, 1, 1);
	sprite2.init(0, 0, 1, 1);
	update();
}

void MainGame::update() {
	while (gameState != GameState::EXIT) {
		draw();
		processInput();
	}
}

void MainGame::initShaders() {
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.linkShader();
}