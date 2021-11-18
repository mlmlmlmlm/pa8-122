#include "BST.h"


BST::BST()
{
	mpRoot = nullptr;
}


BST::~BST()
{
	destroyTree(mpRoot);
}


Node* BST::getRoot()
{
	return mpRoot;
}
void BST::setRoot(Node* nRoot)
{
	mpRoot = nRoot;
}




void BST::destroyTree(Node* killnode)
{
	if (killnode != nullptr)
	{
		destroyTree(killnode->getLeft());
		destroyTree(killnode->getRight());
		delete killnode;
	}
}



void BST::insert(string& nData, int nUnit)
{
	if (mpRoot == nullptr)
	{
		mpRoot = new TransactionNode(nData, nUnit);
	}
	else
	{
		insert(nData, nUnit, mpRoot);
	}
}



void BST::insert(string& nData, int nUnit, Node*& pT)
{

	if (dynamic_cast<TransactionNode*> (pT)->getUnit() > nUnit)  //left condition
	{
		if (dynamic_cast<TransactionNode*> (pT)->getLeft() == nullptr)
		{
			dynamic_cast<TransactionNode*> (pT)->setLeft(new TransactionNode(nData, nUnit));
			return;
		}
		else
		{
			Node* mem = pT->getLeft();
			insert(nData, nUnit, mem);
		}
	}
	else
	{
		if (dynamic_cast<TransactionNode*> (pT)->getRight() == nullptr)
		{
			dynamic_cast<TransactionNode*> (pT)->setRight(new TransactionNode(nData, nUnit));
			return;
		}
		else
		{
			Node* mem = pT->getRight();
			insert(nData, nUnit, mem);
		}

	}



}


void BST::inOrderTrav()
{
	if (mpRoot == nullptr)
	{
		cout << "empty" << endl;
		return;
	}
	inOrderTrav(mpRoot);
}


void BST::inOrderTrav(Node*& pT)
{
	if (pT == nullptr)
	{
		return;
	}

	Node* mem = pT->getLeft();
	inOrderTrav(mem);

	pT->printDat();
	
	Node* mem2 = pT->getRight();
	inOrderTrav(mem2);


}


//These assume very well sorted tree, dont want to have to not recursivly search	

TransactionNode& BST::findLarge()
{
	Node* mem = mpRoot;
	while (mem->getRight() != nullptr)
	{
		mem = mem->getRight();
	}
	return *dynamic_cast<TransactionNode*>(mem);
}


TransactionNode& BST::findSmall()
{
	Node* mem = mpRoot;
	while (mem->getLeft() != nullptr)
	{
		mem = mem->getLeft();
	}
	return *dynamic_cast<TransactionNode*>(mem);
}
