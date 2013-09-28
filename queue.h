#ifndef queue_H
#define queue_H

#include<iostream>
#include "Node.h"

using namespace std;

class queue{

private:
	Node* q[100];
	
	
public:
	int f,r;
	queue();
	bool isEmpty();
	void enqueue(Node* aNode);
	Node* dequeue();
	void display();
};

#endif