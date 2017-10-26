#ifndef _ANIMATION_H_
#define _ANIMATION_H_

class Animation
{
	class State* current;

public:
	Animation(int * x);
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();
	void update();

private:
	int m_timer = 0;
	bool m_idle = true;
};
#endif