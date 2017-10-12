#ifndef _JUMP_H_
#define _JUMP_H_

#include "State.h"
#include "Animation.h"

class Jumping : public State
{
public:
	Jumping(int * x) { m_state_holder = x; };
	~Jumping() {};
	void idle(Animation* a);
};

#endif

