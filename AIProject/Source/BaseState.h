#pragma once

template<class A>
class BaseState
{
public:
	virtual void Enter(A* agent)=0;
	virtual void Tick(A* agent)=0;
	virtual void Exit(A* agent)=0;

protected:
	BaseState() {}
	virtual ~BaseState() = 0 {}
};

