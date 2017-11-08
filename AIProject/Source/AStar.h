#ifndef __AStar__AStar__
#define __AStar__AStar__

#include <iostream>
#include <list>
#include "Node.h"

class AStar
{
public:
    void Run();
	Node** GetGraph();
	int GetxMax();
	int GetyMax();
	int GetStartNode();
	int GetEndNode();
	void Search();

private:
    const static int xMax = 10;
    const static int yMax = 10;
    const static int iStartNode = 0;
    const static int iEndNode = 98;
    
    void CreateGraph();
    void CreateGraphAdjs();
    void CreateNodeAdj(const int iRow, const int iCol);
    
    void ComputeGraphHeuristics();
    void ComputeNodeHeuristic(Node* pNode);
    
    void Clean();
    
    Node* VisitNode();
    void AddNodeToOpenList(Node* pParent, Node* pNode);
    
    void PrintPath(Node* pNode) const;
    

    
    std::list<Node*> qOpenList;

	bool end = false;

	Node* tRoot[xMax * yMax];
};

#endif /* defined(__AStar__AStar__) */
