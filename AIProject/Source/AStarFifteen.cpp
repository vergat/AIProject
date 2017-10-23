#include "AStarFifteen.h"

void AStarFifteen::Run()
{
}

int AStarFifteen::GetxMax()
{
	return 0;
}

int AStarFifteen::GetyMax()
{
	return 0;
}

std::list<int> AStarFifteen::GetStartNode()
{
	return std::list<int>();
}

std::list<int> AStarFifteen::GetEndNode()
{
	return std::list<int>();
}

void AStarFifteen::Search()
{
}

void AStarFifteen::CreateGraph()
{
}

void AStarFifteen::CreateGraphAdjs()
{
}

void AStarFifteen::CreateNodeAdj(const int iRow, const int iCol)
{
}

void AStarFifteen::ComputeGraphHeuristics()
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
