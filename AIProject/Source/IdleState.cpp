#include <iostream>

#include "IdleState.h"
#include "SleepState.h"
#include "EmptyLoadState.h"
#include "GoMineState.h"

void IdleState::Enter(Miner * agent)
{
	agent->SetColor(sf::Color::White);
}

void IdleState::Tick(Miner * agent)
{

	if (agent->GetLoad() > 0)
	{
		std::cout << "Bags are not empty. I'm going to emptying.." << std::endl;
		agent->MachineState->ChangeState(&EmptyLoadState::GetInstance());
	}
	else if (agent->GetFatigue() <= 0)
	{
		std::cout << "I'm exhausted. I go to sleep.." << std::endl;
		agent->MachineState->ChangeState(&SleepState::GetInstance());
	}
	else
	{
		std::cout << "I'm going to mine.." << std::endl;
		agent->MachineState->ChangeState(&GoMineState::GetInstance());
	}
}

void IdleState::Exit(Miner * agent)
{
}
