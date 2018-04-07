#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(int x, int y, int width, int height);
	~Player();

	void Update(EventListener * e);
	void Collision(std::vector<Entity*>* e);

};

