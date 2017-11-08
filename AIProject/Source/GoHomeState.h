#pragma once
#include"BaseState.h"
#include "Miner.h"

class GoHomeState :public BaseState<Miner>
{
public:
	static GoHomeState& GetInstance()
	{
		static GoHomeState instance;
		return instance;
	}

public:
	void Enter(Miner* agent) override;
	void Tick(Miner* agent) override;
	void Exit(Miner* agent) override;

private:
	GoHomeState() {}

public:
	GoHomeState(GoHomeState const&) = delete;
	void operator=(GoHomeState const&) = delete;
};