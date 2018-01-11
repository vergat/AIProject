#include "Miner.h"
#include "IdleState.h"

Miner::Miner(int maxFatigue, int maxLoad)
{
	MachineState = new FSM<Miner>(this);
	m_maxFatigue = maxFatigue;
	m_fatigue = maxFatigue;
	m_maxLoad = maxLoad;
	m_load = 0;
	colorState = sf::Color::White;
}


Miner::~Miner()
{
	delete(MachineState);
	MachineState = nullptr;
}

void Miner::IncreaseFatigue()
{
	m_fatigue++;
}

void Miner::DecreaseFatigue()
{
	m_fatigue--;
}

void Miner::IncreaseLoad()
{
	m_load++;
}

void Miner::DecreaseLoad()
{
	m_load--;
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
	return m_fatigue;
}

int Miner::GetLoad()
{
	return m_load;
}

int Miner::GetMaxFatigue()
{
	return m_maxFatigue;
}

int Miner::GetMaxLoad()
{
	return m_maxLoad;
}
