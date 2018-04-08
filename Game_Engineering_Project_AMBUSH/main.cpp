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
#include "Hunter.h"
#include "Wall.h"
#include "LTimer.h"

#include "Graph.h"

//Data access semaphore
SDL_sem* gDataLock = NULL;

const int speed = 10;

std::vector<Rectangle*> rectPool;
std::vector<Entity*> entityPool;
std::vector<Hunter*> hunterPool;

Graph graph;

int collisionIndex = -1;
int pathFindingIndex = -1;

bool quit = false;

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

	while(!quit)
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

int PathFinding(void* data)
{
	srand(SDL_GetTicks());
	int index = -1;

	while (!quit)
	{
		SDL_Delay(15);
		SDL_SemWait(gDataLock);
		pathFindingIndex++;
		if (pathFindingIndex >= hunterPool.size())
		{
			pathFindingIndex = 0;
		}
		index = pathFindingIndex;
		if (index >= hunterPool.size())
		{
			index = 0;
		}
		SDL_SemPost(gDataLock);
		hunterPool.at(index)->PathFind(&entityPool);
		SDL_Delay(5);
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

	graph.AddNode(19 * 2, 350, "Dublin");

	graph.AddNode(19 * 5, 50, "Kildare");
	graph.AddNode(19 * 5, 550, "Naas");

	graph.AddNode(19 * 15, 370, "Carlow");
	graph.AddNode(19 * 15, 450, "Tullow");

	graph.AddNode(19 * 25, 50, "Galway");
	graph.AddNode(19 * 25, 550, "Salt Hill");

	graph.AddNode(19 * 28, 350, "London");

	graph.AddArc("Dublin", "Kildare");
	graph.AddArc("Dublin", "Naas");

	graph.AddArc("Kildare", "Carlow");
	graph.AddArc("Kildare", "Tullow");
	graph.AddArc("Naas", "Carlow");
	graph.AddArc("Naas", "Tullow");

	graph.AddArc("Galway", "Carlow");
	graph.AddArc("Galway", "Tullow");
	graph.AddArc("Salt Hill", "Carlow");
	graph.AddArc("Salt Hill", "Tullow");

	graph.AddArc("London", "Galway");
	graph.AddArc("London", "Salt Hill");

	for (int i = 0; i < graph.GraphSize(); i++)
	{
		rectPool.push_back(new Rectangle(graph.GetNode(i)->x, graph.GetNode(i)->y, 19, 19, SDL_Color{ 150,0,150, 150 }));
	}


	entityPool.push_back(new Player(19*2, 19*2, 19, 19));

	//Wall
	entityPool.push_back(new Wall(0, 0, 608, 19));
	entityPool.push_back(new Wall(0, 0, 19, 608));
	entityPool.push_back(new Wall(0, 608-19, 608, 19));
	entityPool.push_back(new Wall(608-19, 0, 19, 608));
	//

	//
	entityPool.push_back(new Wall(19 * 5, 200, 19, 300));
	entityPool.push_back(new Wall(19 * 15, 0, 19, 350));
	entityPool.push_back(new Wall(19 * 25, 200, 19, 300));
	//
	for (int i = 0; i < 500; i++)
	{
		hunterPool.push_back(new Hunter(19 * 27, 300, 10, 10, &graph));
		entityPool.push_back(hunterPool.back());
	}

	for (int i = 0; i < entityPool.size(); i++)
	{
		rectPool.push_back(entityPool.at(i)->Rect());
	}

	//Event handler
	SDL_Event e;

	listener = new EventListener();

	srand(SDL_GetTicks());
	SDL_Thread* threadA = SDL_CreateThread(Collision, "Thread A", (void*)"Thread A");	
	SDL_Delay(1);
	SDL_Thread* threadB = SDL_CreateThread(Collision, "Thread B", (void*)"Thread B");

	SDL_Delay(1);

	SDL_Thread* threadC = SDL_CreateThread(PathFinding, "Thread C", (void*)"Thread C");
	SDL_Delay(1);						   
	SDL_Thread* threadD = SDL_CreateThread(PathFinding, "Thread D", (void*)"Thread D");

	InputManager inputManager = InputManager(listener, &e);

	unsigned int lastTime = 0;
	float deltaTime = 0;
	unsigned int currentTime = 0;
	srand(time(NULL));
	bool debug = false;
	srand(time(NULL));
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	LTimer fpsTimer;
	LTimer capTimer;
	int countedFrames = 0;
	fpsTimer.start();

	while (!quit)
	{

		int avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		if (avgFPS > 1)
		{

		}
		++countedFrames;

		int frameTicks = capTimer.getTicks();

		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);

			currentTime = SDL_GetTicks();
			if (currentTime > lastTime)
			{
				deltaTime = ((float)(currentTime - lastTime)) / 1000;

				lastTime = currentTime;

				inputManager.handleInput();

				for (int i = 0; i < entityPool.size(); i++)
				{
					entityPool.at(i)->Update(listener);
				}

				//Render Code
				SDL_SetRenderDrawColor(gameRenderer, 100, 0, 0, 0);
				SDL_RenderClear(gameRenderer);

				for (int i = 0; i < rectPool.size(); i++)
				{
					rectPool.at(i)->Draw(*gameRenderer);
				}
				for (int i = 0; i < graph.GraphSize(); i++)
				{
					for (int j = 0; j < graph.GetNode(i)->arc.size(); j++)
					{
						SDL_SetRenderDrawColor(gameRenderer, 0, 100, 0, 0);
						SDL_RenderDrawLine(gameRenderer, graph.GetNode(i)->arc.at(j)->x + 9, graph.GetNode(i)->arc.at(j)->y+9, graph.GetNode(i)->x+9, graph.GetNode(i)->y+9);
					}
				}

				SDL_RenderPresent(gameRenderer);
			}
		}
	}

	//Wait for threads to finish
	//SDL_WaitThread(threadA, NULL);
	//SDL_WaitThread(threadB, NULL);
}
