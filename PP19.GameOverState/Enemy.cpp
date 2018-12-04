#include "Enemy.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include "AnimatedGraphic.h"


Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0.001);
}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getY() < 0) {
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setY(-2);
	}
	SDLGameObject::update();
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* player = new Player(
		new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(
		new LoaderParams(100, 100, 128, 55, "helicopter2"));
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;
}
