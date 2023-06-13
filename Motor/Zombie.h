#pragma once
#include "Agent.h"
class Zombie : public Agent
{
public:
	Zombie();
	~Zombie();
	void init(glm::vec2 position);
	void update(const vector<string>& levelData, vector<Human*>& humans,
		vector<Zombie*>& zombies);
};

