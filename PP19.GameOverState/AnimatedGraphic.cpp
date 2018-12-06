#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed, int numsFrames)
	: SDLGameObject(pParams), m_animSpeed(animSpeed)
{
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() /
		(1000 / m_animSpeed)) % m_numFrames));
}