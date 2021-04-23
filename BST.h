#pragma once

#include <iostream>
#include <queue>		// helps for utilising Breadth First Showing
#include "NumbersNode.h"

using namespace std;

// HELPER CLASS FOR OUTPUT
class NumbersLevelNode
{
public:
	NumbersNode* number;
	int level;

	NumbersLevelNode(NumbersNode* number, int level)
	{
		this->number = number;
		this->level = level;
	}
};

// BST = Binary Search Tree
class BST
{
public:
	NumbersNode* root = NULL;
	virtual void insert(NumbersNode* newNumber);
	
	// Recursive Traversal Function
	void inOrderTraversal(NumbersNode* current);
	void preOrderTraversal(NumbersNode* current);
	void postOrderTraversal(NumbersNode* current);

	// SHOW
	void show(NumbersNode* p);			// shows the avl breadth traversal for consol
	void showAndWrite(NumbersNode* p);	// shows & writes to text file - I still wanted the show function so I could test with consol and then see final results in text file
};

