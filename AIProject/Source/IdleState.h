#pragma once
#include"BaseState.h"
#include "Miner.h"

class IdleState:public BaseState<Miner>
{
public:
	static IdleState& GetInstance()
	{
		static IdleState instance;
		return instance;
	}

public:
	void Enter(Miner* agent) override;
	void Tick(Miner* agent) override;
	void Exit(Miner* agent) override;

private:
	IdleState() {}

public:
	IdleState(IdleState const&) = delete;
	void operator=(IdleState const&) = delete;
};