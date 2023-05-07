#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include "Sprite.h"
using namespace std;

class SpriteArray
{
private:
	vector<Sprite> sprites;
public:
	SpriteArray();
	~SpriteArray();
	void add();
	void draw();
	void del();
	int get_size();
};

