#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams) : SDLGameObject(pParams) {};
	virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	void handleInput();
};
void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

