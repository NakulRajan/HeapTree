#include "Node.h"

Node :: Node()
{
	data = NULL;
	parent = NULL;
	left = NULL;
	right = NULL;
}

Node :: ~Node()
{
	delete left;
	delete right;
}


