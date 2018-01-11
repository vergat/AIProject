#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include<cstdlib>


#include "MinerScene.h"


MinerScene::MinerScene()
{
	
	for (int index = 0; index < 8; index++)
	{
		miners.push_back(new Miner(rand()%10+1, rand() % 7 + 1));
	}
}

MinerScene::~MinerScene()
{
	//delete(miner);
	//miner = nullptr;
}

void MinerScene::OnIdle()
{
	for (int index = 0; index < miners.size(); index++)
	{
		miners[index]->MachineState->Tick();
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void MinerScene::OnDraw(sf::RenderWindow& renderWindow)
{
	sf::Text text;
	text.setString("Idle state");
	text.setPosition(25, 0);
	text.setCharacterSize(20);
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color::White);
	text.setFont(*(FontManager::Istance()->GetFont(Font_Consola)));
	renderWindow.draw(text);

	text.setString("GoMine state");
	text.setPosition(150, 0);
	text.setFillColor(sf::Color::Yellow);
	renderWindow.draw(text);

	text.setString("GoHome state");
	text.setPosition(300, 0);
	text.setFillColor(sf::Color::Magenta);
	renderWindow.draw(text);
	
	text.setString("Sleep state");
	text.setPosition(475, 0);
	text.setFillColor(sf::Color::Black);
	renderWindow.draw(text);

	text.setString("EmptyLoad state");
	text.setPosition(600, 0);
	text.setFillColor(sf::Color::Cyan);
	renderWindow.draw(text);

	text.setString("Mining state");
	text.setPosition(800, 0);
	text.setFillColor(sf::Color::Blue);
	renderWindow.draw(text);


	sf::Vector2u size= renderWindow.getSize();
	int xMove= size.x / 5;
	int yMove= size.y / 3;
	for (int index = 0; index < miners.size(); index++)
	{
		sf::RectangleShape rectangle(sf::Vector2f(100, 150));
		rectangle.setPosition(sf::Vector2f((xMove*((index%4)+1)) - 50.0f, (yMove*(((index - (index % 4)) / 4) + 1)) - 75.0f));
		rectangle.setFillColor(miners[index]->GetColor());
		renderWindow.draw(rectangle);
	}

}





