#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams) : SDLGameObject(pParams) {};
	virtual void draw();
	virtual void update();
	virtual void clean() {};
};


