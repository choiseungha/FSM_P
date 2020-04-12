#pragma once
#ifndef S_MOVE_H
#define S_MOVE_H

#include "IState.h"
class S_Move : public IState
{
private:

public:
	virtual void Updatae_State()
	{
		printf("S_Move Update\n");
	}
	virtual void OnEnter_State()
	{
		printf("S_Move OnEnter\n");

	}
	virtual void OnExit_State()
	{
		printf("S_Move OnExit\n");

	}

};
#endif

