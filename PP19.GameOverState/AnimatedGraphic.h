#pragma once
#include "SDLGameObject.h"
class AnimatedGraphic : public SDLGameObject
{
public:
	void update();
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
};