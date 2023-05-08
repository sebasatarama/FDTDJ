#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <String>

using namespace std;
enum WindowFlags {
	INVISIBLE = 0X1,
	FULLSCREEN = 0X2,
	BORDERLESS = 0X4,
};

class Window
{
private:
	SDL_Window* window;
	int screenWidth;
	int screenHeight;
public:
	Window();
	~Window();
	void swapWindow();
	int getScreemWidth() {
		return screenWidth;
	}
	int getScreenHeight() {
		return screenHeight;
	}
	int create(string windowNmae, int screenWidth, int screenHeight, unsigned int currentFlags);

};

