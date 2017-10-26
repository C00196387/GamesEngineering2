#include "Entity.h"
#include <typeinfo>

void Entity::removeComponent(Component c)
{
	for (int i = 0; i < m_components.size(); i++)
	{
		if (typeid(m_components.at(i)) == typeid(c))
		{
			m_components.erase(m_components.begin() + i);
		}
	}
}