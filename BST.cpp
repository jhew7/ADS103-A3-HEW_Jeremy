#include "BST.h"

void BST::insert(NumbersNode* newNumber)
{
	// IF the root is NULL(tree is empty), then make this student the root
	if (root == NULL)
	{
		root = newNumber;
		return; // exits function early, we are done here
	}

	// add some pointers to help navigate the tree and find where to insert the newStudent
	NumbersNode* current = root;	// current node we are pointing at
	NumbersNode* parent = NULL;		// parent of the current node (node visited last time)

	while (true)					// Infinite Loop - while loops keep repeating while the statement in the brackets is true,
	{								// if the statement is true then it will always be true and keep repeating. - hence infinite.
		// lets keep track of where we were before moving down further
		parent = current;
		// Now - LEFT or RIGHT
		// if new students studentID is less than the student at the CURRENT NODE
		// then go down LEFT
		if (newNumber->inputNumber < current->inputNumber)
		{
			// < means we go down to the LEFT of the TREE
			current = current->leftChild;
			// if current is NULL, we just found an empty space to insert the newStudent node
			if (current == NULL)
			{
				// done, stick student here
				parent->leftChild = newNumber;
				return;
			}
		}
		else
		{
			// > means we go down to the RIGHT of the TREE
			current = current->rightChild;
			// if current is NULL, we just found an empty space to insert the newStudent node
			if (current == NULL)
			{
				// done, stick student here
				parent->rightChild = newNumber;
				return;
			}
		}
	}
}

// SEARCH FUNCTION
NumbersNode* BST::search(int inputNumber, bool showSearchPath)
{
	// if TREE is EMPTY, can't find student matching studentID then
	if (root == NULL)
	{
		return NULL;
	}

	NumbersNode* current = root;

	// Until find MY studentID keep looping until there's a match
	while (current->inputNumber != inputNumber)
	{

		if (showSearchPath)
		{
			cout << current->inputNumber << endl;
		}

		// haven't found it yet, lefts explore left or right down in the tree
		if (inputNumber < current->inputNumber)
		{
			// go left
			current = current->leftChild;
		}
		else
		{
			// else go right
			current = current->rightChild;
		}
		// if current is NULL, search studentID cannot be found
		if (current == NULL)
		{
			return NULL;
		}
	}
	// While Loop will keep looping until it finds a match
	return current; // should now be pointing to a MATCH in the tree
}

// Outputs stuff in the TREE in ASCENDING ORDER - MOST USEFUL TO US
void BST::inOrderTraversal(NumbersNode* current)
{
	// current == NULL means the end of the branch path, so
	// this IF statement stops it becoming an infinite loop
	// must stop at the end of the branch path
	if (current != NULL)
	{
		inOrderTraversal(current->leftChild);
		cout << current->inputNumber << endl;
		inOrderTraversal(current->rightChild);
	}

}

void BST::preOrderTraversal(NumbersNode* current)
{
	if (current != NULL)
	{
		cout << current->inputNumber << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}

}

void BST::postOrderTraversal(NumbersNode* current)
{
	if (current != NULL)
	{
		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->inputNumber << endl;
	}

}

// Referenced second algorithm here: https://www.geeksforgeeks.org/level-order-tree-traversal/
void BST::show(NumbersNode* p)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue <NumbersLevelNode> q;

	// Enqueue Root and initialise height
	q.push(NumbersLevelNode(root, 0));

	int previousOutputLevel = -1;

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		NumbersLevelNode node = q.front();
		if (node.level != previousOutputLevel)
		{
			cout << endl;
			cout << node.level << " : ";
			previousOutputLevel = node.level;
		}

		cout << node.number->inputNumber << " ";
		q.pop();

		/* Enqueue the LEFT Child */
		if (node.number->leftChild != NULL)
		{
			q.push(NumbersLevelNode(node.number->leftChild, node.level + 1));
		}

		/* Enqueue the RIGHT Child */
		if (node.number->rightChild != NULL)
		{
			q.push(NumbersLevelNode(node.number->rightChild, node.level + 1));
		}
	}

}
