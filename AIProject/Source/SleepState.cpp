#include <iostream>

#include "SleepState.h"
#include "IdleState.h"

void SleepState::Enter(Miner * agent)
{
	agent->SetColor(sf::Color::Black);
}

void SleepState::Tick(Miner * agent)
{
	if (agent->GetFatigue() < 7)
	{
		agent->IncreaseFatigue();
		std::cout << "I'm sleeping" << std::endl;
	}
	else
	{
		agent->MachineState->ChangeState(&IdleState::GetInstance());
	}
}

void SleepState::Exit(Miner * agent)
{
}
