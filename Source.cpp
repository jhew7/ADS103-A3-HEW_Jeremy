/******************************************************************************
*
*  ACADEMIC INTEGRITY DECLARATION
*
*   I, Jeremy Hew declare that except where I have referenced,
*  the work I am are submitting in this attachment is my own work. I
*  acknowledge and agree that the assessor of this assignment may,
*  for the purpose of authenticating this assignment, reproduce it
*  for the purpose of detecting plagiarism. I have read and am aware
*  of the Think Education Policy and Procedure viewable online at
*  http://www.think.edu.au/studying-at-think/policies-and-procedures/
*
******************************************************************************/

#include <iostream>
#include <string>
#include "NumbersNode.h"
#include "BST.h"		// TREE
#include "AVL.h"		// Tree Balancing

using namespace std;

void main()
{
	cout << "==================================" << endl << endl;
	cout << "AVL Tree: In progress..." << endl;
	cout << "==================================" << endl << endl;

	AVL avl1;
	avl1.displayRotations = true;

	avl1.insert(new NumbersNode(23));
	avl1.insert(new NumbersNode(12));
	avl1.insert(new NumbersNode(5));
	avl1.insert(new NumbersNode(8));
	avl1.insert(new NumbersNode(10));
	avl1.insert(new NumbersNode(21));
	avl1.insert(new NumbersNode(11));
	avl1.insert(new NumbersNode(17));
	cout << endl << "Tree height this far: " << avl1.height(avl1.root) << endl;

	cout << "==================================" << endl << endl;
	cout << "Breadth First Traversal" << endl;
	// TREE SHOW BREADTH LEVEL
	avl1.show(avl1.root);
	cout << endl << endl << "The ROOT of this AVL is: " << avl1.root->inputNumber << endl;
	cout << "==================================" << endl << endl;

	/*cout << "Numbers AVL in order traversal" << endl;
	avl1.inOrderTraversal(avl1.root);

	cout << "==================================" << endl << endl;*/

	/*cout << "try find student matching ID: 4343..." << endl;
	NumbersNode* sPtr2 = avl1.search(4343, true);
	if (sPtr2 != NULL)
	{
		cout << "Found: " << sPtr2->inputNumber << endl;
	}
	else
		cout << "Cannot find ID 4343 in avl1 tree!" << endl;*/

	system("pause");
}