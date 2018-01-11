#pragma once

#include "IScene.h"
#include"Miner.h"
#include"FontManager.h"

class MinerScene : public IScene
{
public:
	std::vector <Miner*> miners;
	MinerScene();
	virtual ~MinerScene();
    
	virtual void OnIdle();
	virtual void OnDraw(sf::RenderWindow& renderWindow);
};

