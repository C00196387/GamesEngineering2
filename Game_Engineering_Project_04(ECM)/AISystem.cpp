#include "AISystem.h"
AISystem::AISystem()
{

}

AISystem::~AISystem()
{

}

void AISystem::addEntity(Entity* e)
{ 
	m_entities.push_back(e);
}

void AISystem::update()
{

	for (int i = 0; i < m_entities.size(); i++)
	{
		std::cout << "AI System for Entity " << i;
		for (int j = 0; j < m_entities.at(i)->getComponents().size(); j++)
		{
			if (typeid(*m_entities.at(i)->getComponents().at(j)) == typeid(PositionComponent))
			{
				static_cast<PositionComponent*>(m_entities.at(i)->getComponents().at(j))->setPosition(SDL_Point{ static_cast<PositionComponent*>(m_entities.at(i)->getComponents().at(j))->getPosition().x + 1, static_cast<PositionComponent*>(m_entities.at(i)->getComponents().at(j))->getPosition().y });
				std::cout << " - Position (" << static_cast<PositionComponent*>(m_entities.at(i)->getComponents().at(j))->getPosition().x << "," << static_cast<PositionComponent*>(m_entities.at(i)->getComponents().at(j))->getPosition().y << ")";
			}
			else if (typeid(*m_entities.at(i)->getComponents().at(j)) == typeid(HealthComponent))
			{
				std::cout << " - Health (" << static_cast<HealthComponent*>(m_entities.at(i)->getComponents().at(j))->getHealth() << ")";
			}
		}
		std::cout << "" << std::endl;
	}
}