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

//// GIT HUB LINK: https://github.com/jhew7/ADS103-A3-Q1-HEW_Jeremy

#include <iostream>
#include <string>
#include <fstream>		// File Reading/Writing
#include <vector>		// Storage
#include "NumbersNode.h"
#include "BST.h"		// TREE
#include "AVL.h"		// Tree Balancing

using namespace std;

void main()
{
	// Showing everything to consol first to test
	// I wanted to make sure the program ran correctly first before printing to text
	cout << "==================================" << endl;
	cout << "AVL Tree: In progress..." << endl;
	cout << "==================================" << endl << endl;
	
	// Reading in numbers to work with
	ifstream readFile;
	readFile.open("input-a3q1.txt");
	
	int numberOfTreeNumbers;
	int numbersToSort;
	
	readFile >> numberOfTreeNumbers;
	
	// Setting up storage
	AVL avl1;

	// Loop to store
	for (int i = 0; i < numberOfTreeNumbers; i++)
	{
		int temp;
		readFile >> temp;
		avl1.insert(new NumbersNode(temp));
	}
	
	readFile.close();

	avl1.displayRotations = true;
	cout << endl << "Tree height this far: " << avl1.height(avl1.root) << endl;
	
	// Breadth First Traversal Printing to Consol
	cout << "==================================" << endl;
	cout << "Breadth First Traversal" << endl;
	avl1.show(avl1.root);
	cout << endl << endl << "The ROOT of this AVL is: " << avl1.root->inputNumber << endl;
	cout << "==================================" << endl << endl;
	
	// Breadth First Traversal Printing to Text File
	avl1.showAndWrite(avl1.root);
	
	system("pause");
}