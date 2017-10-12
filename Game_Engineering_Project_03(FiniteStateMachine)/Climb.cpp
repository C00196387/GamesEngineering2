#include "Climb.h"
#include "Idle.h"

void Climbing::idle(Animation* a)
{
	std::cout << "Going from Climbing to Idling" << std::endl;
	*m_state_holder = 0;
	a->setCurrent(new Idle(m_state_holder));
	delete this;
};