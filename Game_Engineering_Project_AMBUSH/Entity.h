#pragma once

#include "Rectangle.h"
#include <string>
#include <vector>
#include "EventListener.h"

class Entity
{
public:
	Entity() {};
	~Entity(){};

	virtual void Update(EventListener * e) = 0;
	virtual void Collision(std::vector<Entity*>* e) = 0;

	Rectangle * Rect() { return m_rect; };
	float *VelocityX() { return &velocityX; };
	float *VelocityY() { return &velocityY; };

	std::string type = "none";

protected:
	Rectangle * m_rect;

	const float speed = 0.5;

	float velocityX = 0;
	float velocityY = 0;

};

