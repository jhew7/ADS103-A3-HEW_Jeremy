#pragma once
#include "BST.h"

// AVL: Adelson, Velski, Landis Binary Tree
class AVL :         // AVL inherits from BST (parent class)
    public BST
{
public:
    bool displayRotations = true;

    int height(NumbersNode* node);

    // DIFFERNCE between left and right sub-trees
    int difference(NumbersNode* node);

    // ROTATIONS
    NumbersNode* RRrotation(NumbersNode* parent);       // RIGHT branch, RIGHT child
    NumbersNode* LLrotation(NumbersNode* parent);       // LEFT branch, LEFT child
    NumbersNode* LRrotation(NumbersNode* parent);       // LEFT branch, RIGHT child
    NumbersNode* RLrotation(NumbersNode* parent);       // RIGHT branch, LEFT child

    // BALANCE
    NumbersNode* balance(NumbersNode* parent);

    // INSERT
    NumbersNode* insertAVL(NumbersNode* parent, NumbersNode* newNumber);

    // insert OVERRIDE from parent (BST.h)
    void insert(NumbersNode* newNumber);
};

