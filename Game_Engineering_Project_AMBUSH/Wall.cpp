#include "Wall.h"



Wall::Wall(int x, int y, int width, int height)
{
	m_rect = new Rectangle(x, y, width, height, SDL_Color{ 200,200,200, 150 });
}

void Wall::Update(EventListener * e)
{

}

void Wall::Collision(std::vector<Entity*>* e)
{

}
