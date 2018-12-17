#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"GameOverState.h"
#include "Background.h"
#include "SDLGameObject.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	for (int i = 0; i < m_back.size(); i++) {
		m_back[i]->update();
	}
	if (SDL_GetTicks() > nextTime1) {		
		nextTime1 = SDL_GetTicks() + TimeLeft;
		m_gameObjects.push_back(new Enemy(new LoaderParams(-200, 0, 50, 80, "helicopter2"),1));
	}

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
		
		
		if (i>3&&checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[i]))) {
			
		
				TheGame::Instance()->getStateMachine()->changeState(
					new GameOverState());
		}

	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {		//pause상태
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
	
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {		//pause상태
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}

}
void PlayState::render()
{
	GameState::render();
}
bool PlayState::onEnter()
{

	if (!TheTextureManager::Instance()->load("assets/rain.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/girl.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/background.png",
		"background", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* player = new Player(new LoaderParams(400, 500, 100, 100 , "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 50, 80, "helicopter2"),1);
	GameObject* background1 = new Background(new LoaderParams(-800, 0, 1600, 600,"background"));

	m_gameObjects.push_back(background1);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("helicopter2");
	TheTextureManager::Instance()->clearFromTextureMap("background");
	std::cout << "exiting PlayState\n";
	return true;

}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}