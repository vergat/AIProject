#include <iostream>
#include <chrono>
#include <thread>


#include "MinerScene.h"


MinerScene::MinerScene()
{
	miner = new Miner();
}

MinerScene::~MinerScene()
{
    
}

void MinerScene::OnIdle()
{
	miner->MachineState->Tick();
	std::this_thread::sleep_for(std::chrono::milliseconds(700));
}

void MinerScene::OnDraw(sf::RenderWindow& renderWindow)
{
	sf::Vector2u size= renderWindow.getSize();
	sf::RectangleShape rectangle(sf::Vector2f(100, 150));
	rectangle.setPosition(sf::Vector2f((size.x/2)-50.0f,(size.y/2) - 75.0f));
	rectangle.setFillColor(miner->GetColor());
	renderWindow.draw(rectangle);
}





