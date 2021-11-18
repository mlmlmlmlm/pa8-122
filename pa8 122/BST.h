#include "TransactionNode.h"


class BST
{
public:
	BST();
	~BST();

	Node* getRoot();
	void setRoot(Node* nRoot);

	void insert(string &nData, int nUnit);
	void inOrderTrav();



	TransactionNode& findSmall();
	TransactionNode& findLarge();

private:
	Node* mpRoot;

	void insert(string& nData, int nUnit, Node*& pT);
	void inOrderTrav(Node*& pT);

	void destroyTree(Node* killnode);
	
};

