#ifndef BinaryHeap_H
#define BinaryHeap_H

#include<iostream>
#include "Node.h"

using namespace std;
class BinaryHeap
{

private: 
	Node *root;
	int treeElements[100];
	int size;
	
public:
	BinaryHeap();
	~BinaryHeap();
	Node* getroot();
	Node* setroot(Node* aRoot);
	int getElement(int i);
	int getSize();
public:	
	void insert(int value);
	Node* heapup(Node* aNode);
	void Display();
	Node* copy(Node* aRoot);
	void switchtree(BinaryHeap* aTree);
	void clear();
	void remove(int value);
	void treeUnion(BinaryHeap* aTree);
	void treeIntersection(BinaryHeap* aTree);
};

#endif

