#include <iostream>

#include "EmptyLoadState.h"
#include "IdleState.h"

void EmptyLoadState::Enter(Miner * agent)
{
	agent->SetColor(sf::Color::Cyan);
}

void EmptyLoadState::Tick(Miner * agent)
{
	if (agent->GetLoad() > 0)
	{
		agent->DecreaseLoad();
		std::cout << "I'm emptying the bags" << std::endl;
	}
	else
	{
		agent->MachineState->ChangeState(&IdleState::GetInstance());
	}
}

void EmptyLoadState::Exit(Miner * agent)
{
}
