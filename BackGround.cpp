#include "BackGround.h"

BackGround::BackGround(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{

}

void BackGround::draw()
{
	SDLGameObject::draw();
}

void BackGround::update()
{
	SDL_Delay(100);
	handleInput();
}

void BackGround::clean()
{

}

void BackGround::handleInput()
{
	if((TheInputHandler::Instance()->getMousePosition()->getX() >= 0 && TheInputHandler::Instance()->getMousePosition()->getX() <= 640) && 
		(TheInputHandler::Instance()->getMousePosition()->getY() >= 50 && TheInputHandler::Instance()->getMousePosition()->getY() <= 430))
		{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			std::cout << "click" << std::endl;
			TheGame::Instance()->m_gameMoney += 100 + TheGame::Instance()->m_clickPowerLevel;
			if (TheGame::Instance()->m_gameMoney >= 1000 && TheGame::Instance()->m_gameMoney <= 1999)
			{
				TheGame::Instance()->m_gameMoneyCount = 1;
			}
			else if (TheGame::Instance()->m_gameMoney >= 2000 && TheGame::Instance()->m_gameMoney <= 2999)
			{
				TheGame::Instance()->m_gameMoneyCount = 2;
			}
			else if (TheGame::Instance()->m_gameMoney >= 3000 && TheGame::Instance()->m_gameMoney <= 3999)
			{
				TheGame::Instance()->m_gameMoneyCount = 3;
			}
			else if (TheGame::Instance()->m_gameMoney >= 4000 && TheGame::Instance()->m_gameMoney <= 4999)
			{
				TheGame::Instance()->m_gameMoneyCount = 4;
			}
			else if (TheGame::Instance()->m_gameMoney >= 5000 && TheGame::Instance()->m_gameMoney <= 5999)
			{
				TheGame::Instance()->m_gameMoneyCount = 5;
			}
			else if (TheGame::Instance()->m_gameMoney >= 6000 && TheGame::Instance()->m_gameMoney <= 6999)
			{
				TheGame::Instance()->m_gameMoneyCount = 6;
			}
			else if (TheGame::Instance()->m_gameMoney >= 7000 && TheGame::Instance()->m_gameMoney <= 7999)
			{
				TheGame::Instance()->m_gameMoneyCount = 7;
			}
			else if (TheGame::Instance()->m_gameMoney >= 8000 && TheGame::Instance()->m_gameMoney <= 8999)
			{
				TheGame::Instance()->m_gameMoneyCount = 8;
			}
			else if (TheGame::Instance()->m_gameMoney >= 9000 && TheGame::Instance()->m_gameMoney <= 9999)
			{
				TheGame::Instance()->m_gameMoneyCount = 9;
			}
			else if (TheGame::Instance()->m_gameMoney >= 10000 && TheGame::Instance()->m_gameMoney <= 10999)
			{
				TheGame::Instance()->m_gameMoneyCount = 10;
			}
			else if (TheGame::Instance()->m_gameMoney >= 11000 && TheGame::Instance()->m_gameMoney <= 11999)
			{
				TheGame::Instance()->m_gameMoneyCount = 11;
			}
			else if (TheGame::Instance()->m_gameMoney >= 12000 && TheGame::Instance()->m_gameMoney <= 12999)
			{
				TheGame::Instance()->m_gameMoneyCount = 12;
			}
			else if (TheGame::Instance()->m_gameMoney >= 13000 && TheGame::Instance()->m_gameMoney <= 13999)
			{
				TheGame::Instance()->m_gameMoneyCount = 13;
			}
			else
			{
				TheGame::Instance()->m_gameMoneyCount = 0;
			}
			switch (TheGame::Instance()->m_gameMoneyCount)
			{
			case 0:
			{
				TheGame::Instance()->m_gameMoneyLevel = 0;
				break;
			}
			case 1:
			{
				TheGame::Instance()->m_gameMoneyLevel = 1000;
				break;
			}
			case 2:
			{
				TheGame::Instance()->m_gameMoneyLevel = 2000;
				break;
			}
			case 3:
			{
				TheGame::Instance()->m_gameMoneyLevel = 3000;
				break;
			}
			case 4:
			{
				TheGame::Instance()->m_gameMoneyLevel = 4000;
				break;
			}
			case 5:
			{
				TheGame::Instance()->m_gameMoneyLevel = 5000;
				break;
			}
			case 6:
			{
				TheGame::Instance()->m_gameMoneyLevel = 6000;
				break;
			}
			case 7:
			{
				TheGame::Instance()->m_gameMoneyLevel = 7000;
				break;
			}
			case 8:
			{
				TheGame::Instance()->m_gameMoneyLevel = 8000;
				break;
			}
			case 9:
			{
				TheGame::Instance()->m_gameMoneyLevel = 9000;
				break;
			}
			case 10:
			{
				TheGame::Instance()->m_gameMoneyLevel = 10000;
				break;
			}
			case 11:
			{
				TheGame::Instance()->m_gameMoneyLevel = 11000;
				break;
			}
			case 12:
			{
				TheGame::Instance()->m_gameMoneyLevel = 12000;
				break;
			}
			case 13:
			{
				TheGame::Instance()->m_gameMoneyLevel = 13000;
				break;
			}
			default:
				break;
			}
		}
	}
}
