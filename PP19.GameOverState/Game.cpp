#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>


InputHandler* InputHandler::s_pInstance = 0;
MenuState* MenuState::s_pInstance = 0;
PlayState* PlayState::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;


	}

	else {
		return false;
	}

	/*if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		std::cout << "TMload error";
		return false;
	}*/


	//m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	//m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(MenuState::Instance());


	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	/*for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	/*for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
	m_pGameStateMachine->update();
}


void Game::clean()
{

	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}

}

void Game::quit()
{
	clean();
}