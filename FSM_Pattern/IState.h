#pragma once
#ifndef ISTATE_H
#define ISTATE_H
#include <iostream>
using namespace std;
class IState
{
public:
	virtual void Updatae_State() = 0;
	virtual void OnEnter_State() = 0;
	virtual void OnExit_State()  = 0;
};


#endif