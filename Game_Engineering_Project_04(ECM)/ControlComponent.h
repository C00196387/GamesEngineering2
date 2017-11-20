#pragma once
#include "Component.h"
#include "InputHandler.h"
class ControlComponent :public Component
{
public:
	ControlComponent(SDL_Event *e)
	{ 
		input = InputHandler(e); 
	};

	InputHandler getInputHandler(int value)
	{
		return input;
	};

private:

	InputHandler input;

};