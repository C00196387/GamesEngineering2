#pragma once

#include "SDL.h"
#include "SDL_keyboard.h"
#include "JumpCommand.h"
#include "ClimbCommand.h"
#include "MacroCommand.h"
#include "Animation.h"

class InputHandler
{
public:

	InputHandler(SDL_Event * e, Animation * x) { m_e = e; commands = new std::list<Command*>; undonCommands = new std::list<Command*>; jumpCommand.init(x);  climbCommand.init(x);}

	void handleInput();

private:

	void undo();
	void redo();

	SDL_Event * m_e;

	JumpCommand jumpCommand;
	ClimbCommand climbCommand;
	MacroCommand macroCommand;
	
	Command* keySpace = &jumpCommand;
	Command* keyZ = &climbCommand;
	Command* keyX = &macroCommand;

	bool recordMode = false;
	bool ctrl = false;

	std::list<Command*>* commands;
	std::list<Command*>* undonCommands;

};