#pragma once
#include "DrawAPI.h"
#include "Character.h"

class Player : public Character
{
public:
	Player(DrawAPI* api) { this->api = api; }
	void Draw() { api->Draw(); }
private:
	DrawAPI* api;
};
