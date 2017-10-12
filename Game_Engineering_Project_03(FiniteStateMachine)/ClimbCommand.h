#pragma once
#include "Command.h"
class ClimbCommand : public Command
{
public:
	virtual void execute() { m_fsm_holder->climbing(); std::cout << "Climb" << std::endl; }
	virtual void undo() { std::cout << "Undone Climb Command" << std::endl; };
};
