#include <iostream>

#include"MiningState.h"
#include"GoHomeState.h"


void MiningState::Enter(Miner * agent)
{
	agent->SetColor(sf::Color::Blue);
}

void MiningState::Tick(Miner * agent)
{
	if (agent->GetFatigue() > 0 && agent->GetLoad()<agent->GetMaxLoad())
	{
		agent->DecreaseFatigue();
		agent->IncreaseLoad();
		std::cout << "Taken 1 iron ore but decrease my energy." << std::endl;
	}
	else
	{
		if (agent->GetLoad() >= agent->GetMaxLoad())
		{
			std::cout << "I'm full with iron." << std::endl;
		}
		else
		{
			std::cout << "I'm exhausted." << std::endl;
		}
		agent->MachineState->ChangeState(&GoHomeState::GetInstance());
	}
}

void MiningState::Exit(Miner * agent)
{
}
