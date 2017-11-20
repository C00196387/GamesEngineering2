#pragma once
#include "Component.h"
#include "InputHandler.h"
class ControlComponent :public Component
{
public:
	ControlComponent()
	{ 
	};

	InputHandler getInputHandler()
	{
		return input;
	};

private:

	InputHandler input;

};