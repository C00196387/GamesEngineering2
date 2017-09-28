#include "InputHandler.h"


void InputHandler::handleInput()
{
	SDL_WaitEvent(m_e);
	switch (m_e->type)
	{
	case SDL_KEYDOWN:
	{
		switch (m_e->key.keysym.sym)
		{
		case SDLK_LCTRL:
		{
			ctrl = true;
			break;
		}
		case SDLK_SPACE:
		{
			if (recordMode)
			{
				macroCommand.add(keySpace);
			}
			else
			{
				keySpace->execute();
				commands->push_back(keySpace);
				undonCommands->clear();
			}
			break;
		}
		case SDLK_z:
		{
			if (recordMode)
			{
				macroCommand.add(keyZ);
			}
			else if (ctrl)
			{
				undo();
			}
			else
			{
				keyZ->execute();
				commands->push_back(keyZ);
				undonCommands->clear();
			}
			break;
		}
		case SDLK_x:
		{
			if (!recordMode)
			{
				keyX->execute();
				commands->push_back(keyX);
				undonCommands->clear();
			}
			break;
		}
		case SDLK_y:
		{
			if (ctrl)
			{
				redo();
			}
			break;
		}
		case SDLK_n:
		{
			recordMode = true;
			macroCommand.clear();
			break;
		}
		case SDLK_m:
		{
			recordMode = false;
			break;
		}
		default:
		{
			break;
		}
		}
		break;
	}
	case SDL_KEYUP:
	{
		switch (m_e->key.keysym.sym)
		{
		case SDLK_LCTRL:
		{
			ctrl = false;
			break;
		}
		}
		break;
	}
	}
}

void InputHandler::undo()
{
	if (commands->size() > 0)
	{
		commands->back()->undo();
		undonCommands->push_back(commands->back());
		commands->pop_back();
	}
}
void InputHandler::redo()
{
	if (undonCommands->size() > 0)
	{
		undonCommands->back()->redo();
		commands->push_back(undonCommands->back());
		undonCommands->pop_back();
	}
}