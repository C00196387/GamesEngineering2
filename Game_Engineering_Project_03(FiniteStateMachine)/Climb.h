#ifndef _CLIMB_H_
#define _CLIMB_H_

#include "State.h"
#include "Animation.h"

class Climbing : public State
{
public:
	Climbing(int * x) { m_state_holder = x; };
	~Climbing() { };

	void idle(Animation* a);
};
#endif