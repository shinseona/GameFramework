#pragma once
#include <string>
#include <vector>
#include"GameObject.h"

class GameState
{
protected:
	std::vector<GameObject*> m_gameObjects;
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit();
	virtual std::string getStateID() const = 0;
};
