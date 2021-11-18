#include "Node.h"


Node::Node()
{
	mpLeft = nullptr;
	mpRight = nullptr;

}


Node::Node(const string& nData)
{
	mpLeft = nullptr;
	mpRight = nullptr;
	mData = nData;
}
Node::~Node()
{
	//cout << "inside decon";
	
}

void Node::setDat(const string& nData)
{
	mData = nData;
}
void Node::setLeft(Node* mLeft)
{
	mpLeft = mLeft;
}
void Node::setRight(Node* mRight)
{
	mpRight = mRight;
}

string Node::getDat()
{
	return mData;
}
Node* Node::getLeft()
{
	return mpLeft;
}
Node* Node::getRight()
{
	return mpRight;
}


