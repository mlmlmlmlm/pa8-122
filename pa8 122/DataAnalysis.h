#include "BST.h"


class DataAnalysis
{
public:
	DataAnalysis() = default;
	~DataAnalysis() = default;


	void runAnalysis();


private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openDat();
	void readFil(int &units, string &type, string &status);
	void passSoldPurch(int& units, string& type, string& status);
	void loopFil();

	void prinTrends();

};

