#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>




Game* Game::s_pInstance = 0;

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



	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(MenuState::Instance());


	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

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
	//TheInputHandler::Instance()->update();
	/*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
*/
}

void Game::quit()
{
	clean();
}