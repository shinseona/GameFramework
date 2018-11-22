#pragma once
#include "GameState.h"
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
		if (s_plnstance == 0)
		{
			s_plnstance = new PlayState();
			return s_plnstance;
		}
		return s_plnstance;
	}	
	
private:
	PlayState();
	PlayState(){}
	static const std::string s_playID;
   static PlayState*  s_pInstance;


};

typedef PlayState ThePlayState;