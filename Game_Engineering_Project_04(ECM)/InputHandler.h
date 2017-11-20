#pragma once

#include "SDL.h"
#include "SDL_keyboard.h"

class InputHandler
{
public:

	InputHandler() {};

	InputHandler(SDL_Event * e) { m_e = e;}

	void handleInput();

private:

	SDL_Event * m_e;

};