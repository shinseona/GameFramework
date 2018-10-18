#include "texturemanager.h"
#include<iostream>
#include "Game.h"



bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}

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

	SDL_RenderClear(m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82,m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100,128, 82, 1, m_currentFrame, m_pRenderer);



	SDL_RenderPresent(m_pRenderer);


}
void Game::update()
{
	mee = int(((SDL_GetTicks() / 100) % 1));
	m_currentFrame = int(((SDL_GetTicks() * 3 / 100) % 6));
	m_currentFrame2 = int(((SDL_GetTicks() / 100) % 6));





}
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
