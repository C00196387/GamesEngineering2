#pragma once
#include "SDL.h"

class Rectangle
{
public:

	Rectangle();
	Rectangle(int x, int y, int width, int height, SDL_Color color);
	~Rectangle() {};

	void Update();
	void Draw(SDL_Renderer & r);

	int X, Y, Width, Height;
	SDL_Color Color;

};

