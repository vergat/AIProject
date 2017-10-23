#include "BaseState.h"

template <A>
class FSM
{
	A* PAgent;
	BaseState<A*> BSCurrent;
public:
	FSM(A* agent)
	{
		PAgent=agent;
	}
	void Tick() 
	{
		BSCurrent->Tick(PAgent);
	}
	void ChangeState(BaseState<A*> NewState)
	{
		BSCurrent->Exit(PAgent);
		BSCurrent = NewState;
		BSCurrent->Enter(PAgent);
	}

};

