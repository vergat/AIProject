#include <iostream>
#include <list>
#include "NodeFifteen.h"

class AStarFifteen
{
public:
	void Run();
	int GetxMax();
	int GetyMax();
	std::list<int> GetStartNode();
	std::list<int> GetEndNode();
	void Search();

private:
	const static int xMax = 5;
	const static int yMax = 5;
	std::list<int> startState = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0 };
	
	std::list<int> endState = {1,2,3,4,
								5,6,7,8,
								9,10,11,12,
								13,14,15,0};

	void CreateGraph();
	void CreateGraphAdjs();
	void CreateNodeAdj(const int iRow, const int iCol);

	void ComputeGraphHeuristics();
	void ComputeNodeHeuristic(NodeFifteen* pNode);

	void Clean();

	NodeFifteen* VisitNode();
	void AddNodeToOpenList(NodeFifteen* pParent, NodeFifteen* pNode);

	void PrintPath(NodeFifteen* pNode) const;



	std::list<NodeFifteen*> qOpenList;

	bool end = false;
};

