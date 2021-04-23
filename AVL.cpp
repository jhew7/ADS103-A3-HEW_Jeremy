#include "AVL.h"

// HEIGHT
int AVL::height(NumbersNode* node)
{
    int h = 0;

    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    return h;
}

// DIFFERENCE
int AVL::difference(NumbersNode* node)
{
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
    parent->rightChild = temp->leftChild;          
    temp->leftChild = parent;
    if (displayRotations)
        cout << "RR Rotation on: " << parent->inputNumber << endl;

    return temp;
}

NumbersNode* AVL::LLrotation(NumbersNode* parent)
{
    NumbersNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;          
    temp->rightChild = parent;
    if (displayRotations)
        cout << "LL Rotation on: " << parent->inputNumber << endl;

    return temp;
}

NumbersNode* AVL::LRrotation(NumbersNode* parent)
{
    // FIRST ROTATION - turning into a LL rotation
    NumbersNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);      
    if (displayRotations)
        cout << "LR Rotation on: " << parent->inputNumber << endl;
    // SECOND ROTATION - calling LL Rotation
    return LLrotation(parent);
}

NumbersNode* AVL::RLrotation(NumbersNode* parent)
{
    // FIRST ROTATION - turning into a RR rotation
    NumbersNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);       
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

    if (balanceFactor > 1)
    {
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
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }

    if (newNumber->inputNumber < parent->inputNumber)
    {
        // goes down the tree to until it finds a spot and then inserts, followed by balancing the tree
        parent->leftChild = insertAVL(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else
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
