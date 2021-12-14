#pragma once
#include "SDLGameObject.h"
#include "SDL.h"
#include "Game.h"

class BackGround : public SDLGameObject
{
public:
	BackGround(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	void handleInput();
};
