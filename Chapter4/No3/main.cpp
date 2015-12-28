#include <iostream>
#include "Node.h"
#include <vector>
using namespace std;

void readIn(Node* node);
void addNode(Node* node);
void printNode(Node* node);
void riseNode(Node* node);

Node* root;
vector<Node*> nodeVector;


int main(){
	cout << "please enter the root:\n";
	int tmp;
	cin >> tmp;
	root = new Node(tmp);
	readIn(root);
	cout << "please enter the node that you want to enter:\n";
	cin >> tmp;
	addNode(new Node(tmp));
	printNode(root);
}

void printNode(Node* node){
	if (node -> getChild(LEFT)){
		cout << node -> getNum() << "'s left child is " << node -> getChild(LEFT) -> getNum() << ".\n";
		printNode(node -> getChild(LEFT));
	}
	if (node -> getChild(RIGHT)){
		cout << node -> getNum() << "'s right child is " << node -> getChild(RIGHT) -> getNum() << ".\n";
		printNode(node -> getChild(RIGHT));
	}
}

void readIn(Node* node){
	if (node == NULL){
		return;
	}
	for (int i = 0 ; i < 2 ; i ++){
		cout << "please enter node No" << node -> getNum() << "'s " << (i == 0 ? "left":"right") << "Node and -2 means null\n";
		int tmp;
		cin >> tmp;
		if (tmp == -2){
			continue;
		}
		node -> setChild(new Node(node , tmp), (i == 0 ? LEFT:RIGHT));
	}
	readIn(node -> getChild(LEFT));
	readIn(node -> getChild(RIGHT));
}

void addNode(Node* node){
	nodeVector.clear();
	nodeVector.push_back(root);
	Node* tmp;
	while(nodeVector.size() != 0){
		tmp = nodeVector.at(0);
		nodeVector.erase(nodeVector.begin());
		if (tmp -> getChild(LEFT) == NULL || tmp -> getChild(RIGHT) == NULL){
			tmp -> setChild(node , (tmp -> getChild(LEFT) == NULL ? LEFT:RIGHT));
			node -> setFather(tmp);
			riseNode(node);
			return;
		}
		nodeVector.push_back(tmp -> getChild(LEFT));
		nodeVector.push_back(tmp -> getChild(RIGHT));
	}
	tmp = root;
	while (tmp -> getChild(LEFT) != NULL){
		tmp = tmp -> getChild(LEFT);
	}
	tmp -> setChild(node, LEFT);
	node -> setFather(tmp);
	riseNode(node);
}
void riseNode(Node* node){
	if (node -> getFather() -> getNum() >= node -> getNum()){
		return;
	}else{
		Node* tmp = node -> getFather();
		Node* tmpLeftChild = tmp -> getChild(LEFT);
		Node* tmpRightChild = tmp -> getChild(RIGHT);
		Node* tmpFather = tmp -> getFather();
		node -> getFather() -> setChild(node -> getChild(LEFT), LEFT);
		node -> getFather() -> setChild(node -> getChild(RIGHT), RIGHT);
		node -> getFather() -> setFather(node);
		node -> setChild(tmpLeftChild == node?tmp:tmpLeftChild, LEFT);
		node -> setChild(tmpRightChild == node?tmp:tmpRightChild, RIGHT);
		node -> setFather(tmpFather);
		tmpFather -> setChild(node, tmpFather -> getChild(LEFT) == tmp ? LEFT:RIGHT);
		riseNode(node);
	}
}
