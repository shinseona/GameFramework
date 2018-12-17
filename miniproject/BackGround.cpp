#include"Background.h"
#include "InputHandler.h"

Background::Background(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void Background::draw()
{
	SDLGameObject::draw();
}
void Background::update()	
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	SDLGameObject::update();

}
void Background::handleInput()
{
	if (m_position.getX() >=-800)
	{
		
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			m_velocity.setX(-2);
			//m_textureID
		}
	}
	if (m_position.getX() <= 800)
	{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			m_velocity.setX(2);
		}
	}
	
}
void Background::clean()
{
}