#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	/*
	// GameObject - Player(��Ӱ���)���迡�� Player�� �������� �������� GameObject���� ����Ǳ� ������ Ư���� �������� �͸� Player�� �������ָ� ��
	void load(int x, int y, int width, int height,
	std::string textureID);
	void draw(SDL_Renderer* pRenderer);*/
	void update();
	void clean() {};
};