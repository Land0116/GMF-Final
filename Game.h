#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include "TextManager.h"
#include "GameObject.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "BackGround.h"
#include "alba.h"

class GameStateMachine;

class Game
{
public:
	static Game* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const {return m_pRenderer;}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() {return m_bRunning; }
	void quit();

	int m_gameMoney;
	//클릭시 돈 추가지급
	int m_gameMoneyLevel;
	int m_gameMoneyCount;
	int m_clickPowerLevel;
	//구매시 자동 돈지급
	int m_timePower;
	int m_Time;
	int m_TimeCount;
	//구매시 자동 돈지급 / 업그레이드
	int m_timePower1;
	int m_Time1;
	int m_TimeCount1;

	GameStateMachine* getStateMachine()
	{
		return m_pGameStateMachine;
	}
	std::vector<GameObject*> m_gameObjects;
private:
	Game() { m_gameMoney = 0; m_gameMoneyCount = 0; m_clickPowerLevel = 0; m_timePower = 0; m_Time = 0; m_TimeCount = 0; m_timePower1 = 0; m_Time1 = 0; m_TimeCount1 = 0; }
	static Game* s_pInstance;

private:
	int m_currentFrame;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	GameStateMachine *m_pGameStateMachine;

};
typedef Game TheGame;