#include "queue.h"


queue :: queue()
{
	f = 0;
	r = -1;
}

bool queue :: isEmpty()
{
	if (f > r) {
		return true;
	}
	return false;
}

void queue :: enqueue( Node* aNode)
{
	if(r > 100){
		cout << "The queue is full" << endl;
		return;
	}
	q[++r] = aNode;
}

Node* queue :: dequeue()
{
	Node* del;
	if (f > r){
		cout << "The queue is empty" << endl;
		exit(1);
	}
	del = q[f++];
	return del;
}

void queue :: display()
{
	int i;
	cout << endl << "The elements of the queue are " << endl;
	
	for(i=f;i<r;i++)
		cout << q[i]->data << "  " ;
	cout << endl;
}
