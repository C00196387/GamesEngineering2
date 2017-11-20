#include "InputHandler.h"


void InputHandler::handleInput(SDL_Event * e)
{
	SDL_PollEvent(e);
	switch (e->type)
	{
	case SDL_KEYDOWN:
	{
		switch (e->key.keysym.sym)
		{
		case SDLK_LCTRL:
		{
			std::cout << "CTRL Pressed" << std::endl;
			break;
		}
		case SDLK_SPACE:
		{
			std::cout << "SPACE Pressed" << std::endl;
			break;
		}
		case SDLK_z:
		{
			std::cout << "Z Pressed" << std::endl;
			break;
		}
		case SDLK_x:
		{
			std::cout << "X Pressed" << std::endl;
			break;
		}
		case SDLK_y:
		{
			std::cout << "Y Pressed" << std::endl;
			break;
		}
		case SDLK_n:
		{
			std::cout << "N Pressed" << std::endl;
			break;
		}
		case SDLK_m:
		{
			std::cout << "M Pressed" << std::endl;
			break;
		}
		default:
		{
			break;
		}
		}
		break;
	}
	case SDL_KEYUP:
	{
		switch (e->key.keysym.sym)
		{
		case SDLK_LCTRL:
		{
			break;
		}
		}
		break;
	}
	}
}