#pragma once

#include <iostream>
#include <queue> // helps for utilising Breadth First Showing
#include "NumbersNode.h"

using namespace std;

// HELPER CLASS FOR OUTPUT
class NumbersLevelNode
{
public:
	NumbersNode* number;
	int level;

	// CONSTRUCTOR
	NumbersLevelNode(NumbersNode* number, int level)
	{
		this->number = number;
		this->level = level;
	}
};

// BST = Binary Search Tree
// root node sort of acting as center
// everything smaller than root is stored on left of root
// everything greater than or equal to root is stored on right
class BST
{
public:
	NumbersNode* root = NULL;
	virtual void insert(NumbersNode* newNumber);
	NumbersNode* search(int inputNumber, bool showSearchPath = false);


	// Recursive Traversal Function
	void inOrderTraversal(NumbersNode* current);
	void preOrderTraversal(NumbersNode* current);
	void postOrderTraversal(NumbersNode* current);

	// SHOW
	void show(NumbersNode* p);			// add show function prototype to the BST Class
};

