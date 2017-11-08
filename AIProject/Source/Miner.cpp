#include "Miner.h"
#include "IdleState.h"

Miner::Miner()
{
	MachineState = new FSM<Miner>(this);
	fatigue = 7;
	load = 0;
	colorState = sf::Color::White;
}


Miner::~Miner()
{
}

void Miner::IncreaseFatigue()
{
	fatigue++;
}

void Miner::DecreaseFatigue()
{
	fatigue--;
}

void Miner::IncreaseLoad()
{
	load++;
}

void Miner::DecreaseLoad()
{
	load--;
}

void Miner::SetColor(sf::Color color)
{
	colorState = color;
}

sf::Color Miner::GetColor()
{
	return colorState;
}

int Miner::GetFatigue()
{
	return fatigue;
}

int Miner::GetLoad()
{
	return load;
}
