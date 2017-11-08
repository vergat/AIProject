#include "AStarFifteen.h"

void AStarFifteen::Run()
{
}

int AStarFifteen::GetxMax()
{
	return xMax;
}

int AStarFifteen::GetyMax()
{
	return yMax;
}

std::vector<int> AStarFifteen::GetStartNode()
{
	return startState;
}

std::vector<int> AStarFifteen::GetEndNode()
{
	return endState;
}

void AStarFifteen::Search()
{
}

void AStarFifteen::CreateNodeAdj(NodeFifteen* node)
{
}

void AStarFifteen::ComputeNodeHeuristic(NodeFifteen * pNode)
{
}

void AStarFifteen::Clean()
{
}

NodeFifteen * AStarFifteen::VisitNode()
{
	return nullptr;
}

void AStarFifteen::AddNodeToOpenList(NodeFifteen * pParent, NodeFifteen * pNode)
{
}

void AStarFifteen::PrintPath(NodeFifteen * pNode) const
{
}
