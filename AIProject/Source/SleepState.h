#pragma once
#include"BaseState.h"
#include "Miner.h"

class SleepState : public BaseState<Miner>
{
public:
	static SleepState& GetInstance()
	{
		static SleepState instance;
		return instance;
	}

public:
	void Enter(Miner* agent) override;
	void Tick(Miner* agent) override;
	void Exit(Miner* agent) override;
private:
	SleepState() {}

public:
	SleepState(SleepState const&) = delete;
	void operator=(SleepState const&) = delete;
};
