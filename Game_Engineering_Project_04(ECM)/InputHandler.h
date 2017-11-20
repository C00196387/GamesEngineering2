#pragma once

#include "SDL.h"
#include "SDL_keyboard.h"
#include <iostream>

class InputHandler
{
public:

	InputHandler() {};

	void handleInput(SDL_Event * e);

private:


};