
#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"
#include <SDL.h>
class Enemy : public GameObject
{
public:
	//void load(int x, int y, int width, int height,
	//	std::string textureID);
	//void draw(SDL_Renderer* pRenderer) {};
	void update();
	//void clean() {};
};



class Player : public GameObject
{
public:
	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};

void Player::load(int x, int y, int width, int height,
	std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Player::clean()
{
	GameObject::clean();
}

void Player::update()
{
	m_x -= 1;
}
