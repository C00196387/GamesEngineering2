#include "Jump.h"
#include "Idle.h"

void Jumping::idle(Animation *a)
{
	std::cout << "Going from Jumping to Idling" << std::endl;
	*m_state_holder = 0;
	a->setCurrent(new Idle(m_state_holder));
	delete this;
}