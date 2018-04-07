#include "Player.h"



Player::Player(int x, int y, int width, int height)
{
	m_rect = new Rectangle(x, y, width, height, SDL_Color{ 250,200,0, 150 });
}


Player::~Player()
{
}

void Player::Update(EventListener * e)
{
	bool buttonPressed = false;
	if (e->A)
	{
		velocityX -= speed;
		buttonPressed = true;
	}
	if (e->D)
	{
		velocityX += speed;
		buttonPressed = true;
	}
	if (e->W)
	{
		velocityY -= speed;
		buttonPressed = true;
	}
	if (e->S)
	{
		velocityY += speed;
		buttonPressed = true;
	}

	if (!buttonPressed)
	{
		velocityX *= 0.8;
		velocityY *= 0.8;
		if (velocityX < 1 && velocityX > -1)
		{
			velocityX = 0;
		}
		if (velocityY< 1 && velocityY > -1)
		{
			velocityY = 0;
		}
	}

	if (velocityX > 10)
	{
		velocityX = 10;
	}
	if (velocityX < -10)
	{
		velocityX = -10;
	}
	if (velocityY > 10)
	{
		velocityY = 10;
	}
	if (velocityY < -10)
	{
		velocityY = -10;
	}

	m_rect->X += velocityX;
	m_rect->Y += velocityY;

}

void Player::Collision(std::vector<Entity*>* e)
{
	for (int i = 0; i < e->size(); i++)
	{
		if (e->at(i) != this)
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
				}
			}
		}
	}
}
