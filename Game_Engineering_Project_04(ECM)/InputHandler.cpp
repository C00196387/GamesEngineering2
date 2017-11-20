#include "InputHandler.h"


void InputHandler::handleInput()
{
	SDL_PollEvent(m_e);
	switch (m_e->type)
	{
	case SDL_KEYDOWN:
	{
		switch (m_e->key.keysym.sym)
		{
		case SDLK_LCTRL:
		{
			break;
		}
		case SDLK_SPACE:
		{
			break;
		}
		case SDLK_z:
		{
			break;
		}
		case SDLK_x:
		{
			break;
		}
		case SDLK_y:
		{
			break;
		}
		case SDLK_n:
		{
			break;
		}
		case SDLK_m:
		{
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
		switch (m_e->key.keysym.sym)
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