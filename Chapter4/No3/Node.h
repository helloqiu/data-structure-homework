#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
#define LEFT 0
#define RIGHT 1

class Node{
public:
	Node(Node* father , int num);
	Node(Node* father);
	Node(int num);
	Node();

	void setFather(Node* father);
	void setNum(int num);
	void setChild(Node* child , int direction);
	Node* getFather();
	int getNum();
	Node* getChild(int direction);
	int getHeight();
private:
	Node* father;
	int num;
	Node* leftChild;
	Node* rightChild;
};
#endif