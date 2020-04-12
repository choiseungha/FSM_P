#pragma once
#include "IState.h"
#include <Windows.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class State_Machine
{
private:
	IState* mCurrentState;
public:
	State_Machine(IState* rState)
	{
		mCurrentState = rState;
	}
	void SetState(IState* rState)
	{
		if (rState == mCurrentState)
		{
			printf("Same State\n");
			return;
		}
		mCurrentState->OnExit_State();
		mCurrentState = rState;
		mCurrentState->OnEnter_State();
	}
	void OnUpdate()
	{
		mCurrentState->Updatae_State();
	}

};