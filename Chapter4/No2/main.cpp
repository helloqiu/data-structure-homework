#include <iostream>
#include "Node.h"

using namespace std;

Node* root = NULL;
void readNode(Node* node);
void outputNode(Node* node);

int main(){

	cout << "please enter the root:\n";
	int tmp;
	cin >> tmp;
	root = new Node(tmp);
	readNode(root);
	outputNode(root);
}

void readNode(Node* node){
	if (node == NULL){
		return;
	}
	for (int i = 0 ; i < 2 ; i ++){
		cout << "please enter NO" << node -> getNum() << "'s " << (i == 0 ? "left " : "right ") << "child and -2 means null\n";
		int tmp;
		cin >> tmp;
		if (tmp == -2){
			continue;
		}
		node -> setChild(new Node(node , tmp), (i == 0?LEFT:RIGHT));
	}
	readNode(node -> getChild(LEFT));
	readNode(node -> getChild(RIGHT));
}
void outputNode(Node* node){
	if (node == NULL){
		return;
	}
	//cout << node->getChild(LEFT) << " , " << node -> getChild(RIGHT) << endl;
	cout << "( " << node -> getNum() << " , " << node -> getHeight() << " )\n";
	outputNode(node -> getChild(LEFT));
	outputNode(node -> getChild(RIGHT));
}