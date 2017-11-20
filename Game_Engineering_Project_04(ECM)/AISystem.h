#pragma once
#include <vector>
#include <iostream>
#include "PositionComponent.h"
#include "HealthComponent.h"
#include "Entity.h"

class AISystem
{
	std::vector<Entity*> m_entities;
public:
	AISystem();
	~AISystem();

	void addEntity(Entity *e);
	void update();
};
