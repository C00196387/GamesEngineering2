#include "Hunter.h"



Hunter::Hunter(int x, int y, int width, int height, Graph * g)
{
	m_rect = new Rectangle(x, y, width, height, SDL_Color{ 20,0,200, 150 });
	graphPointer = g;
	type = "Enemy";
}


Hunter::~Hunter()
{
}

void Hunter::Update(EventListener * e)
{
	if (path.size() != 0)
	{
		velocityX = -(m_rect->X - path.back().x);
		velocityY = -(m_rect->Y - path.back().y);
	}

	if (velocityX > 2)
	{
		velocityX = 2;
	}
	if (velocityX < -2)
	{
		velocityX = -2;
	}
	if (velocityY > 2)
	{
		velocityY = 2;
	}
	if (velocityY < -2)
	{
		velocityY = -2;
	}
	m_rect->X += velocityX;
	m_rect->Y += velocityY;
}

void Hunter::Collision(std::vector<Entity*>* e)
{
	for (int i = 0; i < 9; i++)
	{
		if (e->at(i) != this && e->at(i)->type != "Enemy" && e->at(i)->type != "Player")
		{
			SDL_Rect r1 = SDL_Rect({ m_rect->X, m_rect->Y, m_rect->Width, m_rect->Height });
			SDL_Rect r2 = SDL_Rect({ e->at(i)->Rect()->X, e->at(i)->Rect()->Y, e->at(i)->Rect()->Width, e->at(i)->Rect()->Height });
			SDL_Rect result;
			if (SDL_IntersectRect(&r1, &r2, &result))
			{
				if (result.w > result.h)
				{
					if (r1.y > r2.y)
					{
						m_rect->Y += result.h;
					}
					else
					{
						m_rect->Y -= result.h;
					}
					velocityY = 0;
					velocityX = (((rand() % 10)-5) / 5);
				}
				else
				{
					if (r1.x > r2.x)
					{
						m_rect->X += result.w;
					}
					else
					{
						m_rect->X -= result.w;
					}
					velocityX = 0;
					velocityY = (((rand() % 10) - 5) / 5);
				}
			}
		}
	}
}

void Hunter::PathFind(std::vector<Entity*>* entity)
{
	float distance = 999999999999;

	Node * position1 = graphPointer->GetNode(0);

	for (int i = 0; i < graphPointer->GraphSize(); i++)
	{
		float temp = sqrt(((graphPointer->GetNode(i)->x - m_rect->X) * (graphPointer->GetNode(i)->x - m_rect->X)) + ((graphPointer->GetNode(i)->y - m_rect->Y) * (graphPointer->GetNode(i)->y - m_rect->Y)));
		if (distance > temp && !graphPointer->GetNode(i)->solid)
		{
			distance = temp;
			position1 = graphPointer->GetNode(i);
		}
	}

	distance = 99999999999;
	Node * position2 = graphPointer->GetNode(0);
	for (int i = 0; i < graphPointer->GraphSize(); i++)
	{
		float temp = sqrt(((graphPointer->GetNode(i)->x - entity->at(0)->Rect()->X) * (graphPointer->GetNode(i)->x - entity->at(0)->Rect()->X)) + ((graphPointer->GetNode(i)->y - entity->at(0)->Rect()->Y) * (graphPointer->GetNode(i)->y - entity->at(0)->Rect()->Y)));
		if (distance > temp && !graphPointer->GetNode(i)->solid)
		{
			distance = temp;
			position2 = graphPointer->GetNode(i);
		}
	}

	if (path.size() == 0 || pholder != NULL && position2 != pholder)
	{
		pholder = position2;

		path = graphPointer->Path(position2->x, position2->y, position1->x, position1->y);
	}

	distance = sqrt(((path.back().x - m_rect->X) * (path.back().x - m_rect->X)) + ((path.back().y - m_rect->Y) * (path.back().y - m_rect->Y)));

	if (path.size() > 1 && distance < 35 && distance > -35)
	{
		path.pop_back();
	}
}
