#ifndef __AStar__Node__
#define __AStar__Node__

#include <list>
#include "NodeState.h"

class Node
{
public:
	Node(int x, int y);
	void addAdjNode(Node* node);
	void Heuristics(int h);
	int x;
	int y;
	int F;
	int G;
	int H;
	Node* parent;
	NodeState nodeState;
	std::list<Node*> adjNodes;
};

#endif /* defined(__AStar__Node__) */
