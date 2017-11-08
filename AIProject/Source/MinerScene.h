#pragma once

#include "IScene.h"
#include"Miner.h"

class MinerScene : public IScene
{
public:
	Miner * miner;
	MinerScene();
	virtual ~MinerScene();
    
	virtual void OnIdle();
	virtual void OnDraw(sf::RenderWindow& renderWindow);
};

