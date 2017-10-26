#pragma once

#include <list>
#include <iostream>
#include <iterator>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() { execute(); };
protected:
	Command() {}
};
