#include "Rectangle.h"


Rectangle::Rectangle()
{
	Color = SDL_Color{ 0,0,0,0 };
	X = 0;
	Y = 0;
	Width = 10;
	Height = 10;
}

Rectangle::Rectangle(int x, int y, int width, int height, SDL_Color color)
{
	Color = color;
	X = x;
	Y = y;
	Width = width;
	Height = height;
}

void Rectangle::Draw(SDL_Renderer & r)
{
	SDL_Rect holder;
	holder = SDL_Rect({ X, Y, Width, Height });
	SDL_SetRenderDrawColor(&r, Color.r, Color.g, Color.b, Color.a);
	SDL_RenderFillRect(&r, &holder);
}