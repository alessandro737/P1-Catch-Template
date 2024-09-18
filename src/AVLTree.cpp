//
// Created by Alessandro Giusti on 9/16/2024.
//

#include "AVLTree.h"

int AVLTree::getGatorID() const
{
    return gatorID;
}

string AVLTree::getName()
{
    return name;
}

AVLTree *AVLTree::searchID(AVLTree *root, int key)
{
    if(root == nullptr || root->gatorID == key)
    {
        return nullptr;
    }
    if (key < root->gatorID)
    {
        return searchID(root->left, key);
    }
    else
    {
        return searchID(root->right, key);
    }
}

AVLTree *AVLTree::searchNAME(AVLTree *root, string key)
{
    return nullptr;
}

AVLTree* AVLTree::insertGator(AVLTree *root, int ID, string n)
{
    if(root == nullptr)
    {
        return new AVLTree(ID, n);
    }
    if(ID < root->gatorID)
    {
        root->left = insertGator(root->left, ID, n);
    }
    else
    {
        root->right = insertGator(root->right, ID, n);
    }
    return root;
}
