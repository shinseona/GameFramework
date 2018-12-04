#pragma once

#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }



protected:
	//int m_x;
	//int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

};