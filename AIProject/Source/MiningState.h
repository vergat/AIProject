#pragma once
#include"BaseState.h"
#include "Miner.h"


class MiningState : public BaseState<Miner>
{
public:
	static MiningState& GetInstance()
	{
		static MiningState instance;
		return instance;
	}

public:
	void Enter(Miner* agent) override;
	void Tick(Miner* agent) override;
	void Exit(Miner* agent) override;
private:
	MiningState() {}

public:
	MiningState(MiningState const&) = delete;
	void operator=(MiningState const&) = delete;
};
