#include "Node.h"


class TransactionNode : public Node
{
public:
	TransactionNode(string &nDat, int &nUnit);
	~TransactionNode() = default;

	void printDat();

	int getUnit();
	void setUnit(int &nUn);

private:
	int mUnits;
};



