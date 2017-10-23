#include <list>
#include "NodeState.h"


class NodeFifteen
{
public:
	NodeFifteen();
	~NodeFifteen();
	void addAdjNode(NodeFifteen* node);
	void Heuristics(int h);
	int F;
	int G;
	int H;
	NodeFifteen* parent;
	NodeState nodeState;
	std::list<NodeFifteen*> adjNodes;
	std::list<int> state;
	bool route;
};

