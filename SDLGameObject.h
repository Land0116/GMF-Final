#pragma once
#include "GameObject.h"
#include "VectorManager.h"
#include "InputHandler.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams *pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

public:
	VectorManager getPosition() const {return m_position;}
	int getWidth() const {return m_width;}
	int getHeight() const {return m_height;}

protected:
	VectorManager m_position;
	VectorManager m_velocity;
	VectorManager m_acceleration;

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;
	std::string m_textureID;
};

