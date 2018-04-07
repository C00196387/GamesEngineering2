#pragma once

#include "Entity.h"

class Wall : public Entity
{
public:
	Wall(int x, int y, int width, int height);
	~Wall() {};

	void Update(EventListener * e);
	void Collision(std::vector<Entity*>* e);
};

