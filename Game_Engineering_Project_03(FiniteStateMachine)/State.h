#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
#include "Animation.h"

class State
{
public:

	int * m_state_holder;

	virtual void idle(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	};

	virtual void jumping(Animation* a)
	{
		std::cout << "State::Jumping" << std::endl;
	};

	virtual void climbing(Animation* a)
	{
		std::cout << "State::Climbing" << std::endl;
	};

};
#endif