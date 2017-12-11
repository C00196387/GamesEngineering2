#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <assert.h>
#include "AISystem.h"
#include "Entity.h"

int main()
{
	Entity player;
	PositionComponent * position = new PositionComponent();
	AISystem ais;

	player.addComponent(position);

	ais.addEntity(&player);

	while (!position->Complete())
	{
		ais.update();
		assert(position->getPosition().x >= 0);
		assert(position->getPosition().x <= 10);
	}
	std::cout << "Off the screen" << std::endl;

	system("PAUSE");
}