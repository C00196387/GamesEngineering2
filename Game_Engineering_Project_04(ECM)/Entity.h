#pragma once
#include "Component.h"
#include <vector>
class Entity
{
public:
	Entity() {};
	void addComponent(Component c) { m_components.push_back(c); }
	void removeComponent(Component c);
	std::vector<Component> getComponents() { return m_components; }

	int id;

private:
	std::vector<Component> m_components;
};
