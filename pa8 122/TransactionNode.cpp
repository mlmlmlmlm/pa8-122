#include "TransactionNode.h"

TransactionNode::TransactionNode(string& nDat, int& nUnit)
{

	mUnits = nUnit;
	mData = nDat;
}


int TransactionNode::getUnit()
{
	return mUnits;
}
void TransactionNode::setUnit(int& nUn)
{
	mUnits = nUn;
}


void TransactionNode::printDat()
{
	cout << mData << ", " << mUnits << " units" << endl;
}




