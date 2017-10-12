#include "MacroCommand.h"

void MacroCommand::execute() 
{
	if (!empty)
	{
		std::list<Command*>::iterator i = commands->begin();
		for (i; i != commands->end(); i++)
		{
			Command *c = *i;
			c->execute();
		}
	}
	else
	{
		std::cout << "Empty Macro" << std::endl;
	}
}

void MacroCommand::add(Command* x)
{
	empty = false;
	commands->push_back(x);
}

void MacroCommand::remove(Command *c) 
{
	if (commands->size() > 1)
	{
		empty = false;
	}
	else
	{
		empty = true;
	}
	if (!empty)
	{
		commands->remove(c);
	}
}


