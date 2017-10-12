#pragma once
#include "Command.h"

class JumpCommand : public Command
{
public:
	virtual void execute() { m_fsm_holder->jumping(); std::cout << "Jump" << std::endl; }
	virtual void undo() { std::cout << "Undone Jump Command" << std::endl; };
};
