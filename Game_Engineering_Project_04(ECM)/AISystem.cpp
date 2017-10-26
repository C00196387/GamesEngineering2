#include "AISystem.h"



AISystem::AISystem()
{

}

AISystem::~AISystem()
{

}

void AISystem::addEntity(Entity e)
{ 
	m_entities.push_back(e);
}

void AISystem::update()
{
	std::cout << "AISystem Update" << std::endl;
}