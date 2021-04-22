#include "AVL.h"

// HEIGHT
// using RECURSION we keep exploring down and pass final height values up
int AVL::height(NumbersNode* node)
{
    int h = 0;
    // helps break the recursion cycle when we get to NULLs at the bottom of branches
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        // max will give the bigger of the 2 and discard the smaller
        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    return h;
}

// DIFFERENCE
int AVL::difference(NumbersNode* node)
{
    // If empty tree, well it's balanced so it is 0
    if (node == NULL)
    {
        return 0;
    }

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

// ROTATIONS
NumbersNode* AVL::RRrotation(NumbersNode* parent)
{
    NumbersNode* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;           // this is equal to NULL so it detaches the original parent to be added on later
    temp->leftChild = parent;
    if (displayRotations)
        cout << "RR Rotation on: " << parent->inputNumber << endl;

    return temp;
}

NumbersNode* AVL::LLrotation(NumbersNode* parent)
{
    NumbersNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;           // this is equal to NULL so it detaches the original parent to be added on later
    temp->rightChild = parent;
    if (displayRotations)
        cout << "LL Rotation on: " << parent->inputNumber << endl;

    return temp;
}

// LR & RL Rotations require 2 rotations
// first rotation rotates bottom 2 noddes which turns the structure into a LL or RR rotation
// second rotation operates like a RR or LL rotation to find new parent
NumbersNode* AVL::LRrotation(NumbersNode* parent)
{
    // FIRST ROTATION - turning into a LL rotation
    NumbersNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);       // calling RR rotation to rotate the bottom 2 nodes to make them into a LL rotation
    if (displayRotations)
        cout << "LR Rotation on: " << parent->inputNumber << endl;
    // SECOND ROTATION - calling LL Rotation
    return LLrotation(parent);
}

NumbersNode* AVL::RLrotation(NumbersNode* parent)
{
    // FIRST ROTATION - turning into a RR rotation
    NumbersNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);       // calling LL rotation to rotate the bottom 2 nodes to make them into a RR rotation
    if (displayRotations)
        cout << "RL Rotation on: " << parent->inputNumber << endl;
    // SECOND ROTATION - calling RR Rotation
    return RRrotation(parent);

}

// BALANCING
NumbersNode* AVL::balance(NumbersNode* parent)
{
    // GET BALANCE FACTOR - check to see if it requires balancing
    int balanceFactor = difference(parent);

    // IF balance factor is not within " -1 , 0 , 1 "
    // workout what rotations to do
    if (balanceFactor > 1)
    {
        // this will mean LEFT branch is heavier and needs rotation
        // no work out which LEFT or RIGHT child is heaviest
        if (difference(parent->leftChild) > 0)
        {
            // when left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            // when right child unbalanced
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        // when right branch is heavy, but which child?
        if (difference(parent->rightChild) > 0)
        {
            // when left child is heaviest
            parent = RLrotation(parent);
        }
        else
        {
            // when right child is heaviest
            parent = RRrotation(parent);
        }
    }

    return parent;
}

// INSERTING NODE
NumbersNode* AVL::insertAVL(NumbersNode* parent, NumbersNode* newNumber)
{
    // if sub-tree empty, this becomes the new parent node
    // because this is recursive, it will continue to call until it finds an empty spot
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }

    // if parent is not NULL (no empty space for node)
    // we need to go down either LEFT or RIGHT branches to find a spot
    if (newNumber->inputNumber < parent->inputNumber)
    {
        // goes down the tree to until it finds a spot and then inserts, followed by balancing the tree
        parent->leftChild = insertAVL(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else // assume studentID is >= parent's studentID
    {
        parent->rightChild = insertAVL(parent->rightChild, newNumber);
        parent = balance(parent);

    }

}

// insert OVERRIDE from parent(BST.h)
void AVL::insert(NumbersNode* newNumber)
{
    cout << "Inserting: [ " << newNumber->inputNumber << " ]" << endl;
    root = insertAVL(root, newNumber);
}
