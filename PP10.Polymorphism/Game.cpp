#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;


		// m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);

		// load �κ� ��ġ
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		/*
		m_go.load(100, 100, 128, 82, "animate");
		m_player.load(300, 300, 128, 82, "animate");
		*/

		m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();

		m_go->load(100, 100, 128, 82, "animate");
		m_player->load(300, 300, 128, 82, "animate");
		m_enemy->load(0, 0, 128, 82, "animate");

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
	}
	else
	{
		return false;
	}

	return true;
}

void Game::render() {

	// draw color�� render �����
	SDL_RenderClear(m_pRenderer);

	/*
	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);
	*/

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->draw(m_pRenderer);

	// ȭ�� ����
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	/*
	m_go.update();
	m_player.update();
	*/

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->update();
}

void Game::clean() {

	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);

	SDL_Quit();
}

void Game::handleEvents() {

	SDL_Event event;
	if (SDL_PollEvent(&event)) {

		switch (event.type) {

		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}