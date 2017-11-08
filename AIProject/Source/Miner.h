#pragma once
#include "FSM.h"
#include <sfml/Graphics.hpp>

class Miner
{
private:
	int fatigue;
	int load;
	sf::Color colorState;
public:
	Miner();
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
};

