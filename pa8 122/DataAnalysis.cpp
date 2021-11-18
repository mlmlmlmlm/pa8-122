#include "DataAnalysis.h"

void DataAnalysis::openDat()
{
	mCsvStream.open("data.csv", std::ios::in);
	string tmp;
	getline(mCsvStream, tmp);
}


void DataAnalysis::readFil(int& units, string& type, string& status)
{
	string tmp;
	getline(mCsvStream, tmp, ',');
	units = stoi(tmp);
	getline(mCsvStream, type, ',');
	getline(mCsvStream, status, '\n');

}


void DataAnalysis::passSoldPurch(int& units, string& type, string& status)
{
	if (status == "Sold")
	{
		mTreeSold.insert(type, units);
	}
	else //purchased
	{
		mTreePurchased.insert(type, units);
	}
}


void DataAnalysis::loopFil()
{
	openDat();
	int units;
	string type;
	string status;

	while (!mCsvStream.eof())
	{
		readFil(units, type, status);
		passSoldPurch(units, type, status);
	}

	mCsvStream.close();
}


void DataAnalysis::runAnalysis()
{

	loopFil();
	prinTrends();
	return;
}


void DataAnalysis::prinTrends()
{
	cout << "Most Sold: ";
	mTreeSold.findLarge().printDat();
	cout << "Most Purchased: ";
	mTreePurchased.findLarge().printDat();


	cout << "Least Sold: ";
	mTreeSold.findSmall().printDat();
	cout << "Least Purchased: ";
	mTreePurchased.findSmall().printDat();


}