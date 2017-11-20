#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "SDL_thread.h"

#include "Animation.h"
#include "InputHandler.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//IMG_Init(IMG_INIT_PNG);
	SDL_Event e;
	bool end = false;

	int spriteState = 0;

	int i = 0;

	Animation fsm(&spriteState);

	//SDL Render Window Stuff
	InputHandler input = InputHandler(&e, &fsm);

	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load("Resources/DebugSheet.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,image);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Gameloop
	while (!end)
	{
		Uint32 ticks = SDL_GetTicks();
		Uint32 seconds = ticks / 1000;
		Uint32 sprite = seconds % 2;

		SDL_Rect srcrect = { sprite * 48, spriteState * 48, 48, 48 };
		SDL_Rect dstrect = { 10, 200, 48, 48 };

		input.handleInput();
		fsm.update();

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}