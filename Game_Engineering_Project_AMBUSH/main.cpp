#define SDL_MAIN_HANDLED
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>
#include <vector>

#include <SDL.h>
#include <SDL_thread.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Rectangle.h"
#include "EventListener.h"
#include "InputManager.h"
#include "Player.h"
#include "Wall.h"

//Data access semaphore
SDL_sem* gDataLock = NULL;

//The "data buffer"
int gData = -1;

const int speed = 10;

std::vector<Rectangle*> rectPool;
std::vector<Entity*> entityPool;

int collisionIndex = -1;

EventListener * listener;

SDL_Window* gameWindow = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 608, 608, SDL_WINDOW_SHOWN);
SDL_Renderer* gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);

void close()
{
	//Free semaphore
	SDL_DestroySemaphore(gDataLock);
	gDataLock = NULL;

	//Destroy window    
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;
	gameRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int Collision(void* data)
{

	srand(SDL_GetTicks());
	int index = -1;

	while(true)
	{
		//SDL_Delay(15);
		SDL_SemWait(gDataLock);
		collisionIndex++;
		if (collisionIndex >= entityPool.size())
		{
			collisionIndex = 0;
		}
		index = collisionIndex;
		if (index >= entityPool.size())
		{
			index = 0;
		}
		SDL_SemPost(gDataLock);
		entityPool.at(index)->Collision(&entityPool);
	}

	printf("%s finished!\n\n", data);

	return 0;
}

int main()
{
	gDataLock = SDL_CreateSemaphore(1);

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			rectPool.push_back(new Rectangle(i * 19, j * 19, 19, 19, SDL_Color{ 50,0,0, 150 }));
		}
	}

	entityPool.push_back(new Player(19*2, 19*2, 19, 19));

	//Wall
	entityPool.push_back(new Wall(0, 0, 608, 19));
	entityPool.push_back(new Wall(0, 0, 19, 608));
	entityPool.push_back(new Wall(0, 608-19, 608, 19));
	entityPool.push_back(new Wall(608-19, 0, 19, 608));
	//

	entityPool.push_back(new Wall(19 * 5, 0, 19, 350));
	entityPool.push_back(new Wall(19 * 10, 300, 19, 350));
	entityPool.push_back(new Wall(19 * 15, 0, 19, 350));
	entityPool.push_back(new Wall(19 * 20, 300, 19, 350));
	entityPool.push_back(new Wall(19 * 25, 0, 19, 350));

	for (int i = 0; i < entityPool.size(); i++)
	{
		rectPool.push_back(entityPool.at(i)->Rect());
	}

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Run the threads
	srand(SDL_GetTicks());
	SDL_Thread* threadA = SDL_CreateThread(Collision, "Thread A", (void*)"Thread A");						   
	SDL_Thread* threadB = SDL_CreateThread(Collision, "Thread B", (void*)"Thread B");

	listener = new EventListener();

	InputManager inputManager = InputManager(listener, &e);

	//While application is running
	while (!quit)
	{

		inputManager.handleInput();

		entityPool.at(0)->Update(listener);

		//Render Code
		SDL_SetRenderDrawColor(gameRenderer, 100, 0, 0, 0);
		SDL_RenderClear(gameRenderer);

		for (int i = 0; i < rectPool.size(); i++)
		{
			rectPool.at(i)->Draw(*gameRenderer);
		}

		SDL_RenderPresent(gameRenderer);
	}

	//Wait for threads to finish
	SDL_WaitThread(threadA, NULL);
	SDL_WaitThread(threadB, NULL);
}
