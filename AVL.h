#pragma once
#include "BST.h"


// AVL is a self balancing binary search tree
// AVL: Adelson, Velski, Landis Binary Tree
class AVL :         // AVL inherits from BST (parent class)
    public BST
{
public:
    bool displayRotations = true;

    // works out HEIGHT of sub-tree (left and right branches)
    int height(NumbersNode* node);

    // DIFFERNCE between left and right sub-trees
    int difference(NumbersNode* node);

    // ROTATIONS
    // return new parent (top node) of the subtree
    // and their parameter

    NumbersNode* RRrotation(NumbersNode* parent);       // RIGHT branch, RIGHT child
    NumbersNode* LLrotation(NumbersNode* parent);       // LEFT branch, LEFT child
    NumbersNode* LRrotation(NumbersNode* parent);       // LEFT branch, RIGHT child
    NumbersNode* RLrotation(NumbersNode* parent);       // RIGHT branch, LEFT child

    // BALANCE
    // balances a tree structure where parent is the middle top node
    // returns the new parent after balancing (using rotations)
    NumbersNode* balance(NumbersNode* parent);

    // INSERT
    // recursive insert that considers parent a sub-tree
    // this insert also balances itself
    // returns the new root node of the tree
    NumbersNode* insertAVL(NumbersNode* parent, NumbersNode* newNumber);

    // insert OVERRIDE from parent (BST.h)
    void insert(NumbersNode* newNumber);
};

