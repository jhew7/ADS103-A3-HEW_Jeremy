#include "BST.h"
#include <fstream> // File Reading/Writing

void BST::insert(NumbersNode* newNumber)
{
	if (root == NULL)
	{
		root = newNumber;
		return; 
	}

	
	NumbersNode* current = root;	
	NumbersNode* parent = NULL;		

	while (true)					// Infinite Loop - while loops keep repeating while the statement in the brackets is true,
	{								// if the statement is true then it will always be true and keep repeating. - hence infinite.
		parent = current;
		
		if (newNumber->inputNumber < current->inputNumber)
		{
			current = current->leftChild;
			
			if (current == NULL)
			{
				parent->leftChild = newNumber;
				return;
			}
		}
		else
		{
			current = current->rightChild;
			
			if (current == NULL)
			{
				parent->rightChild = newNumber;
				return;
			}
		}
	}
}

// Outputs the TREE in ASCENDING ORDER 
void BST::inOrderTraversal(NumbersNode* current)
{
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

// NEW Show Function to Write results to text file
void BST::showAndWrite(NumbersNode* p)
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
		// Opening file to get the amount of numbers so I can loop with them
		ifstream readFile;
		readFile.open("input-a3q1.txt");
		int numberOfTreeNumbers;
		int numbersToSort;
		readFile >> numberOfTreeNumbers;

		// Write the results of avl1.show to txt file
		ofstream  writeFile;
		writeFile.open("output-a3q1.txt");

		writeFile << "Breadth First Traversal: has now been writen to file." << endl;
		
		// Loop through all numbers so they all print
		for (int i = 0; i < numberOfTreeNumbers; i++)
		{
			// Print front of queue and remove it from queue
			NumbersLevelNode node = q.front();
			while (node.level != previousOutputLevel)
			{
				writeFile << endl;
				writeFile << node.level << " : ";
				previousOutputLevel = node.level;

			}

			writeFile << node.number->inputNumber << " ";
			q.pop();
			// Enqueue the LEFT Child
			if (node.number->leftChild != NULL)
			{
				q.push(NumbersLevelNode(node.number->leftChild, node.level + 1));
			}

			// Enqueue the RIGHT Child
			if (node.number->rightChild != NULL)
			{
				q.push(NumbersLevelNode(node.number->rightChild, node.level + 1));
			}
		}
		writeFile.close();
	}

}












