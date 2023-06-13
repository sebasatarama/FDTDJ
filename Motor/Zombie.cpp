#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(glm::vec2 position)
{
	this->path = "Textures/circle.png";
	this->position = position;
	this->speed = 0.0;
	color.set(0, 255, 0, 255);
}

void Zombie::update(const vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
}

