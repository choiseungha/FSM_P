#pragma once
#ifndef S_IDLE_H
#define S_IDLE_H
#include "IState.h"

class S_Idle : public IState
{
public:
	virtual void Updatae_State()
	{
		printf("S_Idle Update\n");
	}
	virtual void OnEnter_State()
	{
		printf("S_Idle OnEnter\n");

	}
	virtual void OnExit_State()
	{
		printf("S_Idle OnExit\n");

	}
};


#endif
