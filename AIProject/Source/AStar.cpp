#include <cmath>
#include <list>

#include "AStar.h"

void AStar::Run()
{
    CreateGraph();
    
    CreateGraphAdjs();
    
    ComputeGraphHeuristics();

	AddNodeToOpenList(nullptr, tRoot[iStartNode]);
    Search();
    
    Clean();
}

Node** AStar::GetGraph()
{
	return &tRoot[0];
}

int AStar::GetxMax()
{
	return xMax;
}

int AStar::GetyMax()
{
	return yMax;
}

int AStar::GetStartNode()
{
	return iStartNode;
}

int AStar::GetEndNode()
{
	return iEndNode;
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

	if (upY >= 0) 
	{
		tRoot[nodePosition]->addAdjNode(tRoot[iRow*yMax + upY]);
	}
	if (upX >= 0)
	{
		tRoot[nodePosition]->addAdjNode(tRoot[upX*yMax + iCol]);
	}
	if (downY < yMax) 
	{
		tRoot[nodePosition]->addAdjNode(tRoot[iRow*yMax + downY]);
	}
	if (downX < xMax) 
	{
		tRoot[nodePosition]->addAdjNode(tRoot[downX*yMax + iCol]);
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
    /*** TO DO ***/
}

void AStar::Search()
{
	if (!end)
	{
		Node* currentNode = nullptr;

		if (!qOpenList.empty()) 
		{
			currentNode = VisitNode();
			if (currentNode == tRoot[iEndNode])
			{
				PrintPath(currentNode);
				end = true;
				return;
			}
		}
	}
}

Node* AStar::VisitNode()
{
	Node* visitNode = qOpenList.front();
	qOpenList.pop_front();
	for (std::list<Node*>::iterator it = visitNode->adjNodes.begin(); it != visitNode->adjNodes.end(); it++)
	{
		AddNodeToOpenList(visitNode,(*it));
	}
	return visitNode;
}

void AStar::AddNodeToOpenList(Node* pParent, Node* pNode)
{
	if (pNode->nodeState==NodeState::Unknown) 
	{
		pNode->parent = pParent;
		
		if (qOpenList.empty()) 
		{
			pNode->nodeState = NodeState::Open;
			pNode->F = pNode->H;
			qOpenList.push_back(pNode);
		}
		else 
		{
			pNode->G = pParent->G + 1;
			pNode->F = pNode->G + pNode->H;
			for(std::list<Node*>::iterator it = qOpenList.begin(); it != qOpenList.end(); it++) 
			{
				if ((*it)->F>pNode->F) 
				{
					pNode->nodeState = NodeState::Open;
					qOpenList.insert(it, pNode);
				}
			}
			if (pNode->nodeState == NodeState::Unknown) 
			{
				pNode->nodeState = NodeState::Open;
				qOpenList.push_back(pNode);
			}
		}
	}
	else if (pNode->nodeState == NodeState::Open)
	{
		int newF = (pParent->G + 1) + pNode->H;
		if (newF < pNode->F)
		{
			qOpenList.remove(pNode);
			pNode->G = pParent->G + 1;
			pNode->F = newF;
			for (std::list<Node*>::iterator it = qOpenList.begin(); it != qOpenList.end(); it++)
			{
				if ((*it)->F>pNode->F)
				{
					qOpenList.insert(it, pNode);
				}
			}
		}
	}
}

void AStar::PrintPath(Node* pNode) const
{
	while (pNode!=nullptr)
	{
		std::cout << ((pNode->x*yMax) + pNode->y)<<std::endl;
		pNode->route = true;
		pNode = pNode->parent;
	}
}









