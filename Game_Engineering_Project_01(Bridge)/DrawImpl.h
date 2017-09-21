#pragma once
#include <iostream>
class DrawImpl : public DrawAPI
{
public:
	void Draw() {std::cout << "Draw Impl" << std::endl; }
};
