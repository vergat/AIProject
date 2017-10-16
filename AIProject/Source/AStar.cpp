#include <cmath>
#include <list>

#include "AStar.h"

void AStar::Run()
{
    CreateGraph();
    
    CreateGraphAdjs();
    
    ComputeGraphHeuristics();
    
    Search();
    
    Clean();
}

void AStar::CreateGraph()
{
	for (int x = 0; x < xMax; x++)
	{
		for (int y = 0; y < yMax; y++) 
		{
			Node* node = new Node(x,y);
			tRoot[y + (yMax*x)] = node;
		}
	}
}

void AStar::CreateGraphAdjs()
{
	for (int x = 0; x < xMax; x++)
	{
		for (int y = 0; y < yMax; y++) 
		{
			CreateNodeAdj(x, y);
		}
	}
}

void AStar::CreateNodeAdj(const int iRow, const int iCol)
{
	const int nodePosition(iRow*yMax + iCol);

	int upX= iRow -1;
	int downX= iRow +1;
	int upY= iCol -1;
	int downY= iCol +1;

	if (upY > 0) {
		tRoot[nodePosition]->addAdjNode(tRoot[iRow*yMax+upY]);
	}
	if (upX < xMax) {
		tRoot[nodePosition]->addAdjNode(tRoot[upX*yMax + iCol]);
	}
	if (downY > yMax) {
		tRoot[nodePosition]->addAdjNode(tRoot[iRow*yMax + downY]);
	}
	if (upX > 0) {
		tRoot[nodePosition]->addAdjNode(tRoot[upX*yMax + iCol]);
	}
}

void AStar::ComputeGraphHeuristics()
{
	for (int x = 0; x < xMax; x++)
	{
		for (int y = 0; y < yMax; y++)
		{
			ComputeNodeHeuristic(tRoot[y + (yMax*x)]);
		}
	}
}

void AStar::ComputeNodeHeuristic(Node* pNode)
{
	Node* finalNode = tRoot[iEndNode];
	pNode->Heuristics((std::abs(pNode->x-finalNode->x))+(std::abs(pNode->y - finalNode->y)));
}

void AStar::Clean()
{
    
}

void AStar::Search()
{
	AddNodeToOpenList(nullptr, tRoot[iStartNode]);
	Node* currentNode = nullptr;

	while (!qOpenList.empty()) {
		currentNode = VisitNode();
		if (currentNode == tRoot[iEndNode]) {
			PrintPath(currentNode);
			break;
		}
	}
}

Node* AStar::VisitNode()
{
	return nullptr;
}

void AStar::AddNodeToOpenList(Node* pParent, Node* pNode)
{
	if (pNode->nodeState==NodeState::Unknown) {
		pNode->parent = pParent;
		
		if (qOpenList.empty()) {
			pNode->F = pNode->H;
			qOpenList.push_back(pNode);
		}
		else {
			pNode->G = pParent->G + 1;
			pNode->F = pNode->G + pNode->H;
			for(std::list<Node*>::iterator it = qOpenList.begin(); it != qOpenList.end(); it++) {
				if ((*it)->F>pNode->F) {
					pNode->nodeState = NodeState::Open;
					qOpenList.insert(it, pNode);
				}
			}
			if (pNode->nodeState == NodeState::Unknown) {
				pNode->nodeState = NodeState::Open;
				qOpenList.push_back(pNode);
			}
		}
		
	}
   //If pNode not in openList add to open
   //else If pNode.cost < present.cost 
		//Change cost and chage parent to pParent
}

void AStar::PrintPath(Node* pNode) const
{
    /*if(pNode.parent == nullptr)
		std::cout<<pNode.state;;
	PrintPath(pNode.parent);
	std::cout<<pNode.state;*/
}









