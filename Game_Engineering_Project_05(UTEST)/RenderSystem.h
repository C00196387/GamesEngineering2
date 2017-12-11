#pragma once
#include <vector>
#include <iostream>
#include "PositionComponent.h"
#include "HealthComponent.h"
#include "Entity.h"

class RenderSystem
{
private:
	std::vector<Entity*> m_entities;
public:
	RenderSystem() {};
	~RenderSystem() {};

	void addEntity(Entity *e);
	void update();
};

