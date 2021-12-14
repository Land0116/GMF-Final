#include "PlayState.h"
#include "TextureManager.h"
#include "TextManager.h"
#include "Game.h"
#include "GameObject.h"
#include "PauseState.h"
#include "GameStateMachine.h"
#include "GameOverState.h"
#include <iostream>
#include <string>

const std::string PlayState::s_playID = "PLAY";
PlayState *PlayState::s_pInstance  = nullptr;;

void PlayState::ClickPower()
{
	if (TheGame::Instance()->m_clickPowerLevel >= 0 && TheGame::Instance()->m_clickPowerLevel <= 9 && TheGame::Instance()->m_gameMoney >= 100)
	{
		TheGame::Instance()->m_clickPowerLevel += 1;
		TheGame::Instance()->m_gameMoney -= 100;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 10 && TheGame::Instance()->m_clickPowerLevel <= 39 && TheGame::Instance()->m_gameMoney >= 200)
	{
		TheGame::Instance()->m_clickPowerLevel += 2;
		TheGame::Instance()->m_gameMoney -= 200;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 40 && TheGame::Instance()->m_clickPowerLevel <= 79 && TheGame::Instance()->m_gameMoney >= 400)
	{
		TheGame::Instance()->m_clickPowerLevel += 3;
		TheGame::Instance()->m_gameMoney -= 400;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 80 && TheGame::Instance()->m_clickPowerLevel <= 119 && TheGame::Instance()->m_gameMoney >= 800)
	{
		TheGame::Instance()->m_clickPowerLevel += 5;
		TheGame::Instance()->m_gameMoney -= 800;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 120 && TheGame::Instance()->m_clickPowerLevel <= 179 && TheGame::Instance()->m_gameMoney >= 1000)
	{
		TheGame::Instance()->m_clickPowerLevel += 10;
		TheGame::Instance()->m_gameMoney -= 1000;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 180 && TheGame::Instance()->m_clickPowerLevel <= 299 && TheGame::Instance()->m_gameMoney >= 2000)
	{
		TheGame::Instance()->m_clickPowerLevel += 20;
		TheGame::Instance()->m_gameMoney -= 2000;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 300 && TheGame::Instance()->m_clickPowerLevel <= 699 && TheGame::Instance()->m_gameMoney >= 5000)
	{
		TheGame::Instance()->m_clickPowerLevel += 50;
		TheGame::Instance()->m_gameMoney -= 5000;
	}
	else if (TheGame::Instance()->m_clickPowerLevel >= 700 && TheGame::Instance()->m_clickPowerLevel <= 1099 && TheGame::Instance()->m_gameMoney >= 10000)
	{
		TheGame::Instance()->m_clickPowerLevel += 100;
		TheGame::Instance()->m_gameMoney -= 10000;
	}
}


void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	/*if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()
			->changeState(GameOverState::Instance());
	}*/
	if (TheGame::Instance()->m_gameMoney >= 13000 && TheGame::Instance()->m_gameMoneyCount == 13)
	{
		TheGame::Instance()->getStateMachine()
			->changeState(GameOverState::Instance());
	}
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->
			changeState(PauseState::Instance());
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->draw();
	}
	SDL_Color color_1 = { 0, 255, 0 };
	std::string moneyText = std::to_string(TheGame::Instance()->m_clickPowerLevel);
	TheTextManager::Instance()->WriteText(moneyText.c_str(), 70, 400, 24, color_1, TheGame::Instance()->getRenderer());
	SDL_Color color = { 255, 255, 255 };
	if (TheGame::Instance()->m_gameMoney >= 0 && TheGame::Instance()->m_gameMoney <= 999)
	{
		std::string moneyText = std::to_string(TheGame::Instance()->m_gameMoney) + " Cold";
		TheTextManager::Instance()->WriteText(moneyText.c_str(), 10, 10, 24, color, TheGame::Instance()->getRenderer());
	}
	else if (TheGame::Instance()->m_gameMoney >= 1000 && TheGame::Instance()->m_gameMoney <= 9999)
	{
		std::string moneyText = std::to_string(TheGame::Instance()->m_gameMoney / 1000) + "," + std::to_string(TheGame::Instance()->m_gameMoney - TheGame::Instance()->m_gameMoneyLevel) + " Cold";
		TheTextManager::Instance()->WriteText(moneyText.c_str(), 10, 10, 24, color, TheGame::Instance()->getRenderer());
	}
	else if (TheGame::Instance()->m_gameMoney >= 10000 && TheGame::Instance()->m_gameMoney <= 99999)
	{
		std::string moneyText = std::to_string(TheGame::Instance()->m_gameMoney / 1000) + "," + std::to_string(TheGame::Instance()->m_gameMoney - TheGame::Instance()->m_gameMoneyLevel) + " Cold";
		TheTextManager::Instance()->WriteText(moneyText.c_str(), 10, 10, 24, color, TheGame::Instance()->getRenderer());
	}
}

bool PlayState::onEnter()
{
	std::cout << "PlayState 재생" << std::endl;
	if (!TheTextureManager::Instance()->load("Assets/Player/Player.png", 
	"player", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	/*if (!TheTextureManager::Instance()->load("Assets/Player/KinoStanding.png",
		"PlayerStanding", TheGame::Instance()->getRenderer())) {
		return false;
	}*/
	if (!TheTextureManager::Instance()->load("Assets/Player/BackGround.png",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/Player/alba.png",
		"alba", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/Player/alba_fun.png",
		"alba_fun", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/UI/Click_Power.png",
		"clickpower", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/UI/Click_Timeboost_Power.png",
		"clicktimeboostpower", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/UI/Click_TimePower.png",
		"clicktimepower", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* background = new BackGround(
		new LoaderParams(0, 0, 640, 480, "background"));
	m_gameObjects.push_back(background);

	GameObject* player = new Player(
		new LoaderParams(100, 100, 85, 170, "player"));
	m_gameObjects.push_back(player);

	GameObject* enemy = new Enemy(
		new LoaderParams(0, 0, 0, 0, "alba"));
	m_gameObjects.push_back(enemy);

	GameObject* alba = new Alba(
		new LoaderParams(0, 0, 0, 0, "alba_fun"));
	m_gameObjects.push_back(alba);

	GameObject* button1 = new MenuButton(new LoaderParams(10, 420, 127, 45, "clickpower"), ClickPower);
	m_gameObjects.push_back(button1);
	GameObject* button2 = new MenuButton(new LoaderParams(250, 420, 127, 45, "clicktimeboostpower"), ClickTimeBoostPower);
	m_gameObjects.push_back(button2);
	GameObject* button3 = new MenuButton(new LoaderParams(500, 420, 127, 45, "clicktimepower"), ClickTimePower);
	m_gameObjects.push_back(button3);

	return true;
}

void PlayState::ClickTimeBoostPower()
{
	if (TheGame::Instance()->m_timePower == 0 && TheGame::Instance()->m_gameMoney >= 500)
	{
		TheGame::Instance()->m_gameMoney -= 500;
		TheGame::Instance()->m_timePower = 1;
		TheGame::Instance()->m_TimeCount = 1;
		TheGame::Instance()->m_Time = 10;
	}
}

void PlayState::ClickTimePower()
{
	if (TheGame::Instance()->m_timePower1 == 0 && TheGame::Instance()->m_gameMoney >= 100)
	{
		TheGame::Instance()->m_gameMoney -= 100;
		TheGame::Instance()->m_timePower1 = 1;
		TheGame::Instance()->m_TimeCount1 = 1;
		TheGame::Instance()->m_Time1 = 10;
	}
	if (TheGame::Instance()->m_timePower1 == 1 && TheGame::Instance()->m_gameMoney >= 100)
	{
		TheGame::Instance()->m_TimeCount1 = 2;
		TheGame::Instance()->m_timePower1 = 2;
		TheGame::Instance()->m_gameMoney -= 100;
	}
	else if (TheGame::Instance()->m_timePower1 == 2 && TheGame::Instance()->m_gameMoney >= 200)
	{
		TheGame::Instance()->m_TimeCount1 = 3;
		TheGame::Instance()->m_timePower1 = 3;
		TheGame::Instance()->m_gameMoney -= 200;
	}
	else if (TheGame::Instance()->m_timePower1 == 3 && TheGame::Instance()->m_gameMoney >= 400)
	{
		TheGame::Instance()->m_TimeCount1 = 4;
		TheGame::Instance()->m_timePower1 = 4;
		TheGame::Instance()->m_gameMoney -= 400;
	}
	else if (TheGame::Instance()->m_timePower1 == 4 && TheGame::Instance()->m_gameMoney >= 800)
	{
		TheGame::Instance()->m_TimeCount1 = 5;
		TheGame::Instance()->m_timePower1 = 5;
		TheGame::Instance()->m_gameMoney -= 800;
	}
	else if (TheGame::Instance()->m_timePower1 == 5 && TheGame::Instance()->m_gameMoney >= 1000)
	{
		TheGame::Instance()->m_TimeCount1 = 6;
		TheGame::Instance()->m_timePower1 = 6;
		TheGame::Instance()->m_gameMoney -= 1000;
	}
	else if (TheGame::Instance()->m_timePower1 == 6 && TheGame::Instance()->m_gameMoney >= 1500)
	{
		TheGame::Instance()->m_TimeCount1 = 7;
		TheGame::Instance()->m_timePower1 = 7;
		TheGame::Instance()->m_gameMoney -= 1500;
	}
	else if (TheGame::Instance()->m_timePower1 == 7 && TheGame::Instance()->m_gameMoney >= 2000)
	{
		TheGame::Instance()->m_TimeCount1 = 8;
		TheGame::Instance()->m_timePower1 = 8;
		TheGame::Instance()->m_gameMoney -= 2000;
	}
	else if (TheGame::Instance()->m_timePower1 == 8 && TheGame::Instance()->m_gameMoney >= 2500)
	{
		TheGame::Instance()->m_TimeCount1 = 9;
		TheGame::Instance()->m_timePower1 = 9;
		TheGame::Instance()->m_gameMoney -= 2500;
	}
	else if (TheGame::Instance()->m_timePower1 == 9 && TheGame::Instance()->m_gameMoney >= 3000)
	{
		TheGame::Instance()->m_TimeCount1 = 10;
		TheGame::Instance()->m_timePower1 = 10;
		TheGame::Instance()->m_gameMoney -= 3000;
	}
}

bool PlayState::onExit()
{
	std::cout << "PlayState나가기" << std::endl;

	for (int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("alba");
	TheTextureManager::Instance()->clearFromTextureMap("alba_fun");
	TheTextureManager::Instance()->clearFromTextureMap("clickpower");
	TheTextureManager::Instance()->clearFromTextureMap("clicktimeboostpower");
	TheTextureManager::Instance()->clearFromTextureMap("clicktimepower");
	return true;
}

//충돌 체크하는 코드 - 제가 쓰는 게임에는 필요없음
//bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
//{
//	int leftA, leftB;
//	int rightA, rightB;
//	int topA, topB;
//	int bottomA, bottomB;
//
//	leftA = p1->getPosition().getX();
//	rightA = p1->getPosition().getX() + p1->getWidth();
//	topA = p1->getPosition().getY();
//	bottomA = p1->getPosition().getY() + p1->getHeight();
//
//	leftB = p2->getPosition().getX();
//	rightB = p2->getPosition().getX() + p2->getWidth();
//	topB = p2->getPosition().getY();
//	bottomB = p2->getPosition().getY() + p2->getHeight();
//
//	if (bottomA <= topB) { return false; }
//	if (topA >= bottomB) { return false; }
//	if (rightA <= leftB) { return false; }
//	if (leftA >= rightB) { return false; }
//
//	return true;
//}