#include <iostream>

#include "GoMineState.h"
#include "MiningState.h"

void GoMineState::Enter(Miner * agent)
{
	agent->SetColor(sf::Color::Yellow);
}

void GoMineState::Tick(Miner * agent)
{
	std::cout << "I'm going to mine!" << std::endl;
	agent->MachineState->ChangeState(&MiningState::GetInstance());
}

void GoMineState::Exit(Miner * agent)
{
}
