#ifndef _IDLE_H_
#define _IDLE_H_
#include <iostream>

#include "Animation.h"
#include "Jump.h"
#include "Climb.h"

class Idle : public State
{
public:
	Idle(int * x) { m_state_holder = x; };
	~Idle() { };
	void jumping(Animation* a)
	{
		std::cout << "Jumping" << std::endl;
		*m_state_holder = 1;
		a->setCurrent(new Jumping(m_state_holder));
		delete this;
	}

	void climbing(Animation* a)
	{
		std::cout << "Climbing" << std::endl;
		*m_state_holder = 2;
		a->setCurrent(new Climbing(m_state_holder));
		delete this;
	}
};
#endif