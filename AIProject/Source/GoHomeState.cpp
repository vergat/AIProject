#include <iostream>

#include "GoHomeState.h"
#include "IdleState.h"

void GoHomeState::Enter(Miner * agent)
{
	agent->SetColor(sf::Color::Yellow);
}

void GoHomeState::Tick(Miner * agent)
{
	std::cout << "I'm going to home!" << std::endl;
	agent->MachineState->ChangeState(&IdleState::GetInstance());
}

void GoHomeState::Exit(Miner * agent)
{
}
