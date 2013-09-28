#ifndef Node_H
#define Node_H

#include<iostream>
using namespace std;


class Node {
public:
	int data;
	Node *parent; 
	Node *left;
	Node *right;
	
	Node();
	~Node();
};

#endif