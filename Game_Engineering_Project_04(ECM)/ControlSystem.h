#pragma once
#include <vector>
#include <iostream>
#include "PositionComponent.h"
#include "HealthComponent.h"
#include "ControlComponent.h"
#include "Entity.h"

class ControlSystem
{
private:
	std::vector<Entity*> m_entities;
	SDL_Event * m_e;
public:
	ControlSystem();
	~ControlSystem() {};

	void addEntity(Entity *e);
	void update();
};

