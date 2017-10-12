#pragma once

#include <list>
#include <iostream>
#include <iterator>
#include "Animation.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() { execute(); };

	void init(Animation * x) { m_fsm_holder = x; }

	Animation * m_fsm_holder;

protected:
	Command() {}
};
