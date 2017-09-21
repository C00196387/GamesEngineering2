#include "Character.h"
#include <iostream>

#pragma once
class Player : public Character {
public:
	void draw() 
	{
		std::cout << "Draw Player" << std::endl;
	}
};
