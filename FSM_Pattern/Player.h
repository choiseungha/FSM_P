#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "State_Machine.h"
#include <map>	
#include "S_Idle.h"
#include "S_Move.h"
#include <stdio.h>
#include <conio.h>
#pragma warning (disable: 4996)
class Player
{
private:
	enum class Player_State
	{
		Idle=0,
		Move,
		Jump,
		Attack,
		Dead,
	};
	State_Machine * mStateMachine;
	map<Player_State, IState *> map_State;
	IState* mS_Idle;
	IState* mS_Move;
	map<Player_State, IState*>::iterator iter;

public:
	Player()
	{
		mStateMachine = nullptr;
		mS_Idle = nullptr;
		mS_Move = nullptr;
	}
	~Player()
	{

	}
	void Initialize()
	{
		if (mS_Idle == nullptr)
		{
			mS_Idle = new S_Idle;
		}
		if (mS_Move == nullptr)
		{
			mS_Move = new S_Move;
		}
		
		//		state_map.insert(make_pair(state, rstate));
		map_State.insert(make_pair(Player_State::Idle, mS_Idle));
		map_State.insert(make_pair(Player_State::Move, mS_Move));
		mStateMachine = new State_Machine(new S_Idle);
	}
	void State_Check()
	{
		int key = 0;
		int i = 0;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 72:
				case 75:
				case 77:
				case 80:
					iter = map_State.find(Player_State::Move);
					if (iter != map_State.end())
					{
						mStateMachine->SetState(iter->second);
					}
					break;
				default:
					
					break;
				}
			}
		}
		else
		{
			iter = map_State.find(Player_State::Idle);
			if (iter != map_State.end())
			{
				mStateMachine->SetState(iter->second);
			}
		}
		
		
	}
	void State_Run()
	{
		mStateMachine->OnUpdate();
	}

	
};

#endif