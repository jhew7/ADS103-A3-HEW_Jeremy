#pragma once

#include <iostream>
#include <string>

using namespace std;

class NumbersNode
{
public:
	int inputNumber;

	NumbersNode* leftChild;
	NumbersNode* rightChild;

	NumbersNode(int inputNumber);
};

