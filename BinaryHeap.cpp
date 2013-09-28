#include "BinaryHeap.h"
#include "queue.h"

BinaryHeap :: BinaryHeap()
{
	root = NULL;
	size = 0;
}

Node* BinaryHeap :: getroot()
{
	return root;
}

Node* BinaryHeap :: setroot(Node* aRoot)
{
	root = aRoot;
}

void BinaryHeap :: insert (int value)
{
	Node *temp;
	Node *cur;
	
	queue q1,q2;
	
	if(root == NULL)
	{
		root = new Node;
		root->data = value;
		return;
	}
   
   q2.enqueue(root);
   while ((!q2.isEmpty())) {
		cur = q2.dequeue();
		if (cur->data == value) {
			return;
		}
		if (cur->left != NULL) {
			q2.enqueue(cur->left);
		}
		if (cur->right != NULL) {
			q2.enqueue(cur->right);
		}
     }
	
	temp = new Node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	
	q1.enqueue(root);
	while (!(q1.isEmpty())) {
		cur = q1.dequeue();
		
	   if (cur->left != NULL) {
			q1.enqueue(cur->left);
		}
		else {
			cur->left = temp;
			temp->parent = cur;
			heapup(cur->left);
			return;
		}
		if (cur->right != NULL) {
			q1.enqueue(cur->right);
		}
		else {
			cur->right = temp;
			temp->parent = cur;
			heapup(cur->right);
			return;
		}
	}
}


void BinaryHeap :: Display ()
{
    queue q2;
	Node *cur;
	int i = 0;
	
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return;
	}
	
	q2.enqueue(root);
	while ((!q2.isEmpty())) {
		cur = q2.dequeue();
		cout << cur->data << "   ";
		treeElements[i] = cur->data;
		if (cur->left != NULL) {
			q2.enqueue(cur->left);
		}
		if (cur->right != NULL) {
			q2.enqueue(cur->right);
		}
		i++;
	}
	size = i;
}

Node* BinaryHeap :: heapup(Node* aNode)
{ 
	Node* temp;
	if(aNode->parent == NULL)
	{
		return root;
	}
	if (aNode->parent->data < aNode->data) {
		temp = new Node;
		temp->data = aNode->parent->data;
		aNode->parent->data = aNode->data;
		aNode->data = temp->data;
		heapup(aNode->parent);
	}
}
	
Node* BinaryHeap :: copy(Node* aRoot)
{
	Node* temp;
	temp = new Node;
	
	if (aRoot == NULL) {
		return NULL;
	}
	temp->data = aRoot->data;
	temp->parent = aRoot->parent;
	temp->left = copy(aRoot->left);
	temp->right = copy(aRoot->right);
	return temp;
}
	
void BinaryHeap :: switchtree(BinaryHeap* aTree)
{
	Node* temp;
    temp = root;
	root = aTree->root;
	aTree->root = temp;
}

int BinaryHeap :: getElement(int i)
{
	return treeElements[i];
}

int BinaryHeap :: getSize()
{
	return size;
}

void BinaryHeap :: treeUnion(BinaryHeap* aTree)
{
	int i;
	cout << endl << "H1:" << "    " << endl;
	this->Display();
	cout << endl << "H2:" << "    " << endl; 
	aTree->Display();
	
	for (i=0; i<aTree->getSize(); i++) {
		insert(aTree->getElement(i));
	}
	cout << endl << "-----------------------------------------------" << endl;
	cout << endl << "H1:" << "    " << endl;
	this->Display();
}

void BinaryHeap :: treeIntersection(BinaryHeap* aTree)
{
	int i,j,k;
	int n=0;
	int temp[200];
	cout << endl << "H1:" << "    " << endl;
	this->Display();
	cout << endl << "H2:" << "    " << endl; 
	aTree->Display();
	
	for (i=0; i< size; i++) {
		for (j=0; j<aTree->getSize(); j++) {
			if(treeElements[i] == aTree->getElement(j))
			{
				temp[n++]=treeElements[i];
				break;
			}
		}
	}
	this->clear();
	for (k=0; k<n;k++) {
		insert(temp[k]);
		}
	cout << endl << "-----------------------------------------------" << endl;
	cout << endl << "H1:" << "    " << endl;
	this->Display();
}

void BinaryHeap :: remove(int value)
{
	int i;
	int j = 0;
	int temp[200];
	if(root == NULL)
	{  
		cout << endl << "H1:" << "    " << "Empty Tree" << endl;
		return;
	}
	cout << endl << "H1:" << "    " << endl;
	this->Display();
	
	for (i=0; i<size; i++) {
		if (!(treeElements[i] == value)) {
			temp[j++] = treeElements[i];
		}		
	}
	
	this->clear();
	for (i=0; i<j; i++) {
		insert(temp[i]);
	}
	cout << endl <<"-----------------------------------------------" << endl;
	cout << endl << "H1:" << "    " << endl;
	this->Display();
	
}
	

void BinaryHeap :: clear ()
{
	delete root;
	root = NULL;
	size = 0;
	
}

BinaryHeap :: ~BinaryHeap()
{
	delete root;
	
}