#pragma once
#include"BaseState.h"
#include "Miner.h"

class EmptyLoadState :public BaseState<Miner>
{
public:
	static EmptyLoadState& GetInstance()
	{
		static EmptyLoadState instance;
		return instance;
	}

public:
	void Enter(Miner* agent) override;
	void Tick(Miner* agent) override;
	void Exit(Miner* agent) override;

private:
	EmptyLoadState() {}

public:
	EmptyLoadState(EmptyLoadState const&) = delete;
	void operator=(EmptyLoadState const&) = delete;
};