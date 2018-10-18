#include "texturemanager.h"
#include<iostream>
#include "Game.h"



bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true; SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 255, 255);
		m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
		m_textureManager.load("Assets/me.png", "hello", m_pRenderer);
		m_go.load(100, 100, 128, 82, "animate");
		m_player.load(300, 300, 128, 82, "animate");


		//SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");




		/* = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
		*/

		m_bRunning = true;

	}
	else {
		return false;
	}


	return true;

}
void Game::render()
{

	SDL_RenderClear(m_pRenderer); // draw colour·Î Áö¿ò
	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);


}
void Game::update()
{
	m_go.update();
	m_player.update();
}

y
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();

}
void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}