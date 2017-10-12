#include "Animation.h"
#include "Idle.h"

Animation::Animation(int * x)
{
	current = new Idle(x);
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
	m_idle = false;
	m_timer = 10000;
}

void Animation::climbing()
{
	current->climbing(this);
	m_idle = false;
	m_timer = 10000;
}

void Animation::update()
{
	if (m_timer <= 0 && m_idle != true)
	{
		idle();
		m_idle = true;
	}
	else
	{
		m_timer--;
	}
}
