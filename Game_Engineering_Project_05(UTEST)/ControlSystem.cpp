#include "ControlSystem.h"



ControlSystem::ControlSystem()
{
	m_e = new SDL_Event();
}

void ControlSystem::addEntity(Entity* e)
{
	m_entities.push_back(e);
}

void ControlSystem::update()
{

	for (int i = 0; i < m_entities.size(); i++)
	{
		for (int j = 0; j < m_entities.at(i)->getComponents().size(); j++)
		{
			if (typeid(*m_entities.at(i)->getComponents().at(j)) == typeid(ControlComponent))
			{
				static_cast<ControlComponent*>(m_entities.at(i)->getComponents().at(j))->getInputHandler().handleInput(m_e);
			}
		}
	}
}