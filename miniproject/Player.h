#pragma once
#include "SDLGameObject.h"
#include "Camera.h"
class Player : public SDLGameObject
{
private:
	void handleInput();

public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	float Mx = 0;
	float My = 0;
	//int PlayerX = 300, PlayerY = 200, PlayerW, PlayerH;
	
};