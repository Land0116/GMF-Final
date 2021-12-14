#pragma once
#include "SDLGameObject.h"
#include "SDL.h"

class Alba : public SDLGameObject
{
public:
	Alba(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};