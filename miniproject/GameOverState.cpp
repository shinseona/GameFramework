#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "InputHandler.h"
#include <SDL.h>
#include <iostream>

const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = 0;

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new MenuState());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new PlayState());
}
void GameOverState::update()
{
	GameState::update();
}

void GameOverState::render()
{
	GameState::render();
}


bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(300, 100, 190, 30, "gameovertext"), 2,2);

	GameObject* button1 = new MenuButton(
		new LoaderParams(300, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	GameObject* button2 = new MenuButton(
		new LoaderParams(300, 300, 200, 80, "restartbutton"),
		s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering GameOverState\n";
	return true;

}

bool GameOverState::onExit()
{
	if (!GameState::onExit())
		return false;

	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("restartbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting GameOverState\n";
	return true;
}