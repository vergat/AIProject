#include <list>
#include <vector>
#include "NodeState.h"


class NodeFifteen
{
public:
	NodeFifteen();
	~NodeFifteen();
	void addAdjNode(NodeFifteen* node);
	int F;
	int G;
	int H;
	NodeFifteen* parent;
	NodeState nodeState;
	std::list<NodeFifteen*> adjNodes;
	std::vector<int> state;
	bool route;
};

