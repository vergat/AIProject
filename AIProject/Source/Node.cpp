#include "Node.h"

Node::Node(int m_x, int m_y) {
	x = m_x;
	y = m_y;
	nodeState = NodeState::Unknown;
	F = 0;
	G = 0;
	parent = nullptr;
	route = false;
}

void Node::addAdjNode(Node * node)
{
	adjNodes.push_back(node);
}

void Node::Heuristics(int h)
{
	H = h;
}
