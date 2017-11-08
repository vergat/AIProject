#pragma once
#include"BaseState.h"
#include "Miner.h"

class GoMineState :public BaseState<Miner>
{
public:
	static GoMineState& GetInstance()
	{
		static GoMineState instance;
		return instance;
	}

public:
	void Enter(Miner* agent) override;
	void Tick(Miner* agent) override;
	void Exit(Miner* agent) override;

private:
	GoMineState() {}

public:
	GoMineState(GoMineState const&) = delete;
	void operator=(GoMineState const&) = delete;
};