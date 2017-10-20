#pragma once

#include "IScene.h"
#include "FontManager.h"
#include "AStar.h"
#include <assert.h>
#include <vector>
#include <list>
#include <time.h>
#include <sstream>




class AStarScene : public IScene
{

public:
	AStar alg;
	AStarScene();
	Node** graph;
	virtual void OnIdle(void);
	virtual void OnDraw(sf::RenderWindow&);
    
	virtual ~AStarScene(void);

};


