#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "SDL_thread.h"
#include "HealthComponent.h"
#include "AISystem.h"
#include "PositionComponent.h"
#include "RenderSystem.h"
#include "ControlSystem.h"

#include "InputHandler.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//IMG_Init(IMG_INIT_PNG);

	AISystem ais;
	RenderSystem rs;

	HealthComponent hc;

	bool end = false;

	int spriteState = 0;

	int i = 0;

	Entity player;
	Entity cat;
	Entity dog;
	Entity alien;

	ControlSystem cs;

	player.addComponent(new HealthComponent);
	player.addComponent(new PositionComponent);
	player.addComponent(new ControlComponent);

	cat.addComponent(new PositionComponent());
	cat.addComponent(new HealthComponent());

	dog.addComponent(new PositionComponent());
	dog.addComponent(new HealthComponent());

	alien.addComponent(new PositionComponent());
	alien.addComponent(new HealthComponent());

	ais.addEntity(&cat);
	ais.addEntity(&alien);
	ais.addEntity(&dog);

	cs.addEntity(&player);

	rs.addEntity(&player);
	rs.addEntity(&cat);
	rs.addEntity(&alien);
	rs.addEntity(&dog);

	//SDL Render Window Stuff
	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load("Resources/DebugSheet.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,image);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	int timer = 0;

	//Gameloop
	while (!end)
	{
		cs.update();
		if (timer <= 0)
		{
			ais.update();
			rs.update();
			timer = 10000;
		}
		else
		{
			timer--;
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	return 0;


	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}