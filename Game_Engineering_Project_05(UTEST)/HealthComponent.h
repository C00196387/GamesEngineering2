#pragma once
#include "Component.h"
class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {}

	/* Data Only */
	int getHealth() 
	{
		return health;
	}

	void setHealth(int value) 
	{ 
		health = value;
	}

private:

	int health;

};
