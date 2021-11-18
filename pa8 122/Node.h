#include <iostream>
#include <string>
#include <fstream>
#include <vector>}
#include <ctime>

using std::getline;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Node
{
public:
    Node();
    Node(const string& nData);
    virtual ~Node();

    void setDat(const string& nData);
    void setLeft(Node* mLeft);
    void setRight(Node* mRight);

    string getDat();
    Node* getLeft();
    Node* getRight();

    virtual void printDat() = 0;

protected:
    string mData;
    Node* mpLeft;
    Node* mpRight;

};