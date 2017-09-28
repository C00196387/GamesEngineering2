#pragma once
#include "Command.h"
#include "FireCommand.h"
#include "JumpCommand.h"

class MacroCommand : public Command 
{
public:
	MacroCommand() { commands = new std::list<Command*>; }
	virtual ~MacroCommand(){}
	virtual void clear() { if (!empty) { commands->clear(); } };
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
	virtual void undo() { std::cout << "Undone Macro Command" << std::endl; };
private:
	std::list<Command*>* commands;
	bool empty = true;
};