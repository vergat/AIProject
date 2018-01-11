#pragma once
#include "FSM.h"
#include <sfml/Graphics.hpp>

class Miner
{
private:
	int m_maxFatigue;
	int m_maxLoad;
	int m_fatigue;
	int m_load;
	sf::Color colorState;
public:
	Miner(int maxFatigue, int maxLoad);
	~Miner();
	FSM<Miner>* MachineState;

	void IncreaseFatigue();
	void DecreaseFatigue();
	
	void IncreaseLoad();
	void DecreaseLoad();

	void SetColor(sf::Color color);
	sf::Color GetColor();

	int GetFatigue();
	int GetLoad();
	int GetMaxFatigue();
	int GetMaxLoad();
};

