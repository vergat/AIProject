#include <iostream>
#include <list>
#include <vector>
#include "NodeFifteen.h"

class AStarFifteen
{
public:
	void Run();
	int GetxMax();
	int GetyMax();
	std::vector<int> GetStartNode();
	std::vector<int> GetEndNode();
	void Search();

private:
	const static int xMax = 5;
	const static int yMax = 5;
	std::vector<int> startState = {	15,2,1,12,
									8,5,6,11,
									4,9,10,7,
									3,14,13,0 };
	
	std::vector<int> endState = {	1,2,3,4,
								5,6,7,8,
								9,10,11,12,
								13,14,15,0};

	void CreateNodeAdj(NodeFifteen* node);
	void ComputeNodeHeuristic(NodeFifteen* pNode);

	void Clean();

	NodeFifteen* VisitNode();
	void AddNodeToOpenList(NodeFifteen* pParent, NodeFifteen* pNode);

	void PrintPath(NodeFifteen* pNode) const;

	std::list<NodeFifteen*> qOpenList;

	bool end = false;
};

