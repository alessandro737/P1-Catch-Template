//
// Created by Alessandro Giusti on 9/16/2024.
//

#include "TreeNode.h"

#include <iostream>
#include <ostream>

int TreeNode::getGatorID() const
{
    return gatorID;
}

string TreeNode::getName()
{
    return name;
}

TreeNode *TreeNode::search(TreeNode *root, int key)
{
    if(root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return nullptr;
    }
    else if(root->gatorID == key)
    {
        cout << root->name << endl;
        return root;
    }
    if (key < root->gatorID)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

TreeNode *TreeNode::search(TreeNode *root, string key)
{
    if (root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return nullptr;
    }

    if (root->name == key)
    {
        cout << root->gatorID << endl;
    }

    // keep searching for other instances
    search(root->left, key);
    search(root->right, key);

    //Todo: add conditional for not found case
}

TreeNode* TreeNode::insert(TreeNode *root, int key, string val)
{
    if(root == nullptr)
    {
        cout << "successful" << endl;
        return new TreeNode(key, val);
    }
    if(key < root->gatorID)
    {
        root->left = insert(root->left, key, val);
    }
    else if (key > root->gatorID)
    {
        root->right = insert(root->right, key, val);
    }
    else
    { // insertion failed we probably have a duplicate
        cout << "unsuccessful" << endl;
    }

    // todo: balance tree

    return root;
}

TreeNode* TreeNode::remove(TreeNode* root, int key)
{
    if (root == nullptr)
    {
        cout << "unsuccessful" << endl;
        return nullptr;
    }

    if (key < root->gatorID)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->gatorID)
    {
        root->right = remove(root->right, key);
    }
    else
    { // The item is in the local root
        if (root->left == nullptr && root->right == nullptr)
        { // no children
            delete root;
            cout << "successful" << endl;
            return nullptr;
        }
        else if (root->left == nullptr)
        { // one child on right
            TreeNode *temp = root->right;
            delete root;
            cout << "successful" << endl;
            return temp;
        }
        else if (root->right == nullptr)
        { // one child on left
            TreeNode *temp = root->left;
            delete root;
            cout << "successful" << endl;
            return temp;
        }
        else
        { //two children find inorder successor
            TreeNode *temp = findMin(root->right);
            root->gatorID = temp->gatorID;
            root->name = temp->name;
            root->right = remove(root->right, temp->gatorID);
            cout << "successful" << endl;
        }
    }

    // Optional Todo: Balance tree

    return root;
}

TreeNode* TreeNode::findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode * TreeNode::findMax(TreeNode *node) {
    TreeNode* current = node;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

