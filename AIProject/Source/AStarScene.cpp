#include "AStarScene.h"
#include "AStar.h"
#include <chrono>
#include <thread>
AStarScene::AStarScene()
{
    alg.Run();
	graph = alg.GetGraph();
}

AStarScene::~AStarScene()
{
    
}

void AStarScene::OnIdle()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	alg.Search();
}

void AStarScene::OnDraw(sf::RenderWindow& renderWindow)
{
	for (int xIndex = 0; xIndex < alg.GetxMax(); xIndex++)
	{
		for (int yIndex = 0; yIndex < alg.GetyMax(); yIndex++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(50, 50));
			rectangle.setPosition(sf::Vector2f(0.0f+(50.0f*yIndex), 0.0f+(50.0f*xIndex)));
			if ((yIndex + (alg.GetyMax()*xIndex))==alg.GetStartNode())
			{
				rectangle.setFillColor(sf::Color::Green);
			}
			else if ((yIndex + (alg.GetyMax()*xIndex)) == alg.GetEndNode())
			{
				rectangle.setFillColor(sf::Color::Yellow);
			}
			else
			{
				if (graph[yIndex + (alg.GetyMax()*xIndex)]->nodeState == NodeState::Unknown)
				{
					rectangle.setFillColor(sf::Color::Blue);
				}
				else if (graph[yIndex + (alg.GetyMax()*xIndex)]->nodeState == NodeState::Open)
				{
					rectangle.setFillColor(sf::Color::Cyan);
				}
				else
				{
					rectangle.setFillColor(sf::Color::Magenta);
				}
				if (graph[yIndex + (alg.GetyMax()*xIndex)]->route)
				{
					rectangle.setFillColor(sf::Color::Red);
				}
			}
			renderWindow.draw(rectangle);
		}
	}
}
