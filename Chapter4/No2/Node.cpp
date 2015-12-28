#include "Node.h"

Node::Node(Node* father , int num){
	this -> father = father;
	this -> num = num;
	this -> leftChild = NULL;
	this -> rightChild = NULL;
}
Node::Node(Node* father){
	this -> father = father;
	this -> num = 0;
	this -> leftChild = NULL;
	this -> rightChild = NULL;
}
Node::Node(int num){
	this -> num = num;
	this -> father =  NULL;
	this -> leftChild = NULL;
	this -> rightChild = NULL;
}
Node::Node(){
	this -> num = 0;
	this -> father = NULL;
	this -> leftChild = NULL;
	this -> rightChild = NULL;
}
void Node::setFather(Node *father){
	this -> father = father;
}
void Node::setNum(int num){
	this -> num = num;
}
void Node::setChild(Node *child, int direction){
	if (direction == LEFT){
		this -> leftChild = child;
		return;
	}else{
		this -> rightChild = child;
		return;
	}
}
Node* Node::getFather(){
	return this -> father;
}
int Node::getNum(){
	return this -> num;
}
Node* Node::getChild(int direction){
	if (direction == LEFT){
		return this -> leftChild;
	}else{
		return this -> rightChild;
	}
}
int Node::getHeight(){
	int height = 0;
	Node* now = this;
	while (now -> father != NULL){
		height += 1;
		now = now -> father;
	}
	return height;
}