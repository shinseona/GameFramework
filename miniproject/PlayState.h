#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
class GameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}	
	bool colli = false;
	
private:
	//PlayState() = default;
	static const std::string s_playID;
	static PlayState*  s_pInstance;
	std::vector<GameObject*> m_back;
	std::vector<GameObject*> m_player;
	std::vector<GameObject*> m_enemys;
	int TimeLeft = 500;	;
	int nextTime1 = 0;	
	int Heart = 3;		//¸ñ¼û¼ö
	int save = 0;
	int saveTime = 1800;



};

	typedef PlayState ThePlayState;