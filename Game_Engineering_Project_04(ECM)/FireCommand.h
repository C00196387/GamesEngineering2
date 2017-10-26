#pragma once
#include "Command.h"
class FireCommand : public Command
{
public:
	virtual void execute() { std::cout << "Fire" << std::endl; }
	virtual void undo() { std::cout << "Undone Fire Command" << std::endl; };
};
