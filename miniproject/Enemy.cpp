#include "Enemy.h"
#include "InputHandler.h"
#include <SDL.h>
Enemy::Enemy(const LoaderParams* pParams, int numsFrames) : SDLGameObject(pParams), m_numFrames(numsFrames)
{
	m_velocity.setX(5);
	m_velocity.setY(0.001);
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getX() < 0) {
		m_velocity.setX(5);
	}
	else if (m_position.getX() > 500) {
		m_velocity.setX(-5);
	}
	SDLGameObject::update();

}
void Enemy::clean()
{
}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}