#pragma once
#include"GameState.h"

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
	static PauseState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PauseState();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	static PauseState* s_pInstance;
	//std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_back;
	int TimeLeft = 250;	//1000 -> 1초
	int invinTime = 1700;	//1.7초 무적
	int nextTime = 0;			//다음 적이 나오는 시간 (현재시간 + TimeLeft 로 조절)
	int myHeart = 4;		//목숨수
	int invin = 0;	//무적시간 체킹
}; typedef PauseState ThePauseState;