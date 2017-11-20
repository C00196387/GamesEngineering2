#pragma once
#include "Component.h"
#include "SDL.h"
class PositionComponent :public Component
{
public:
	PositionComponent() { position.x = 0; position.y = 0; };

	SDL_Point getPosition()
	{
		return position;
	}

	void setPosition(SDL_Point pos)
	{
		position = pos;
	}

private:

	SDL_Point position;

};

