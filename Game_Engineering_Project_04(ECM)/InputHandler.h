#pragma once

#include "SDL.h"
#include "SDL_keyboard.h"
#include "JumpCommand.h"
#include "FireCommand.h"
#include "MacroCommand.h"

class InputHandler
{
public:

	InputHandler(SDL_Event * e) { m_e = e; commands = new std::list<Command*>; undonCommands = new std::list<Command*>;}

	void handleInput();

private:

	void undo();
	void redo();

	SDL_Event * m_e;

	JumpCommand jumpCommand;
	FireCommand fireCommand;
	MacroCommand macroCommand;
	
	Command* keySpace = &jumpCommand;
	Command* keyZ = &fireCommand;
	Command* keyX = &macroCommand;

	bool recordMode = false;
	bool ctrl = false;

	std::list<Command*>* commands;
	std::list<Command*>* undonCommands;

};