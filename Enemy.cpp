#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(const LoaderParams *pParams) : 
SDLGameObject(pParams)
{
	
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	if (TheGame::Instance()->m_timePower == 1)
	{
		m_position.setX(200);
		m_position.setY(100);
		m_width = 100;
		m_height = 100;
		if (TheGame::Instance()->m_TimeCount == 1)
		{
			TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount;
			SDL_Delay(TheGame::Instance()->m_Time);
		}
	}

}

void Enemy::clean()
{

}
