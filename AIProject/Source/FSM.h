#pragma once
#include "BaseState.h"

template <class A>
class FSM
{
	A* PAgent;
	BaseState<A>* BSCurrent;
public:
	FSM(A* agent)
	{
		PAgent=agent;
		BSCurrent = &(IdleState::GetInstance());
	}
	void Tick() 
	{
		BSCurrent->Tick(PAgent);
	}
	void ChangeState(BaseState<A>* NewState)
	{
		BSCurrent->Exit(PAgent);
		BSCurrent = NewState;
		BSCurrent->Enter(PAgent);
	}
};

