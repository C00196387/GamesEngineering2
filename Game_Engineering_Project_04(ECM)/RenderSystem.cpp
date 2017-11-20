#include "RenderSystem.h"

void RenderSystem::addEntity(Entity* e)
{
	m_entities.push_back(e);
}

void RenderSystem::update()
{

	for (int i = 0; i < m_entities.size(); i++)
	{
		std::cout << "Render System for Entity " << i << " Rendering";
		std::cout << "" << std::endl;
	}
}