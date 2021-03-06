#pragma once
#include "GameState.h"
class GameObject;
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}	
	
private:
	//PlayState() = default;
	static PlayState*  s_pInstance;
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;



};

typedef PlayState ThePlayState;