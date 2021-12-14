#include "alba.h"
#include "Game.h"

Alba::Alba(const LoaderParams* pParams) :
SDLGameObject(pParams)
{

}

void Alba::draw()
{
	SDLGameObject::draw();
}

void Alba::update()
{
	if (TheGame::Instance()->m_timePower1 >= 1)
	{
		m_position.setX(500);
		m_position.setY(100);
		m_width = 100;
		m_height = 100;
		switch (TheGame::Instance()->m_TimeCount1)
		{
			case 1:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 2:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 3:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 4:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 5:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 6:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 7:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 8:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 9:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
			case 10:
			{
				TheGame::Instance()->m_gameMoney += TheGame::Instance()->m_TimeCount1;
				SDL_Delay(TheGame::Instance()->m_Time1);
				break;
			}
		default:
			break;
		}
	}

}

void Alba::clean()
{

}
