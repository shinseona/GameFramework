#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include <vector>

using namespace std;


class Game
{
public:
	Game() {}
	~Game() {}

	vector<GameObject*> m_gameObjects;

	GameObject *m_go;
	Player *m_player;
	Enemy *m_enemy;

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_RendererFlip* m_pRendererFlip;

	int m_currentFrame;
	TextureManager* m_textureManager;

	bool m_bRunning;
};