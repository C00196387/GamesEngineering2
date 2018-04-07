#include "InputManager.h"

void InputManager::handleInput()
{

	while (SDL_PollEvent(m_event))
	{
		switch (m_event->type)
		{
		case SDL_KEYDOWN:
			if (!m_event->key.repeat)
			{
				switch (m_event->key.keysym.sym)
				{
				case SDLK_w:
					m_eventListener->W = true;
					break;

				case SDLK_a:
					m_eventListener->A = true;
					break;

				case SDLK_s:
					m_eventListener->S = true;
					break;

				case SDLK_d:
					m_eventListener->D = true;
					break;

				default:
					break;
				}
				break;
			}

		case SDL_KEYUP:
			if (!m_event->key.repeat)
			{
				switch (m_event->key.keysym.sym)
				{
				case SDLK_w:
					m_eventListener->W = false;
					break;

				case SDLK_a:
					m_eventListener->A = false;
					break;

				case SDLK_s:
					m_eventListener->S = false;
					break;

				case SDLK_d:
					m_eventListener->D = false;
					break;

				default:
					break;
				}
				break;
			}
		}
	}
}