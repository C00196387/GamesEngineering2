#include <SDL.h>
#include "InputHandler.h"
#include <iostream>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event e;
	bool end = false;

	//SDL Render Window Stuff
	InputHandler input = InputHandler(&e);

	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Gameloop
	while (!end)
	{
		input.handleInput();
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

	}

	system("PAUSE");
	SDL_Quit;

	return 0;
}