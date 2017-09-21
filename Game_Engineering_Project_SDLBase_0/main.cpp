#include <SDL.h>
#include <SDL_IMAGE.h>
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{

	DEBUG_MSG("GAME OBJECT CREATED");
	Game* game = new Game();
	game->Initialize("DGPP Skelatol", 0, 0, 1355, 768, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_FOCUS);
	DEBUG_MSG("GAME INITIALIZED");

	DEBUG_MSG("GAME LOOP STARTING.....");

	while (game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}
	
	DEBUG_MSG("Calling Cleanup");
	game->CleanUp();

	return 0;
}