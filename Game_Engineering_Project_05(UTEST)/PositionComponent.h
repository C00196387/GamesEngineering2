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
		if (!complete)
		{
			position = pos;
			if (position.x > 10)
			{
				position.x = 0;
				position.y += 1;
			}
			else if (position.x < 0)
			{
				position.x = 10;
			}

			if (position.y > 10)
			{
				complete = true;
			}
		}
	}

	bool Complete() { return complete; };

private:

	bool complete = false;
	SDL_Point position;

};

