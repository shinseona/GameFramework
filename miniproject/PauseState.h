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
	int TimeLeft = 250;	//1000 -> 1��
	int invinTime = 1700;	//1.7�� ����
	int nextTime = 0;			//���� ���� ������ �ð� (����ð� + TimeLeft �� ����)
	int myHeart = 4;		//�����
	int invin = 0;	//�����ð� üŷ
}; typedef PauseState ThePauseState;