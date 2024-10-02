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

TreeNode::~TreeNode()
{
    if (left) {
        delete left;
        left = nullptr;
    }

    if (right) {
        delete right;
        right = nullptr;
    }
}

TreeNode *TreeNode::search(TreeNode *root, int key)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root->gatorID == key)
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

TreeNode *TreeNode::search(TreeNode *root, const string& key, bool& found)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->name == key)
    {
        cout << root->gatorID << endl;
        found = true;
    }

    // keep searching for other instances pre-order
    search(root->left, key, found);
    search(root->right, key, found);

    return root;
}

TreeNode* TreeNode::insert(TreeNode *root, int key, const string& val)
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
        return root;
    }

    root->height = 1 + max(root->left == nullptr ? 0 : root->left->height,
                           root->right == nullptr ? 0 : root->right->height);

    int balanceFactor = (root->left ? root->left->height : 0) -
                        (root->right ? root->right->height : 0);

    if (balanceFactor < -1)
    { // right heavy?
        // Check if right subtree is left heavy
        int rightChildBalance = (root->right->left ? root->right->left->height : 0) -
                                (root->right->right ? root->right->right->height : 0);

        if (rightChildBalance > 0)
        {
            // Perform right-left rotation
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        else
        {
            // Perform left rotation
            root = leftRotate(root);
        }
    }
    // Else if tree is left heavy
    else if (balanceFactor > 1)
    {
        // Check if left subtree is right heavy
        int leftChildBalance = (root->left->left ? root->left->left->height : 0) -
                               (root->left->right ? root->left->right->height : 0);

        if (leftChildBalance < 0)
        {
            // Perform left-right rotation
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        else
        {
            // Perform right rotation
            root = rightRotate(root);
        }
    }

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
            return nullptr;
        }
        else if (root->left == nullptr)
        { // one child on right
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        { // one child on left
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        { //two children find inorder successor
            TreeNode *temp = findMin(root->right);
            root->gatorID = temp->gatorID;
            root->name = temp->name;
            root->right = remove(root->right, temp->gatorID);
        }
    }

    cout << "successful" << endl;
    return root;
}

void TreeNode::printInorder(const TreeNode *root, bool& firstPrinted)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left, firstPrinted);
    if (firstPrinted)
    {
        cout << ", ";
    }
    cout << root->name;
    firstPrinted = true;
    printInorder(root->right, firstPrinted);

}

void TreeNode::printPreorder(const TreeNode *root, bool& firstPrinted)
{
    if ( root == nullptr)
    {
        return;
    }

    if (firstPrinted)
    {
        cout << ", ";
    }
    cout << root->name;
    firstPrinted = true;
    printPreorder(root->left, firstPrinted);
    printPreorder(root->right, firstPrinted);

}

void TreeNode::printPostorder(const TreeNode *root, bool& firstPrinted)
{
    if ( root == nullptr)
    {
        return;
    }

    printPostorder(root->left, firstPrinted);
    printPostorder(root->right, firstPrinted);
    if (firstPrinted)
    {
        cout << ", ";
    }
    cout << root->name;
    firstPrinted = true;
}

void TreeNode::printLevelCount(const TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << root->height << endl;
    }
}

TreeNode * TreeNode::removeInorder(TreeNode *root, const int N)
{
    if (root == nullptr) {
        cout << "unsuccessful" << endl;
        return nullptr;
    }

    int count = 0;
    TreeNode *target = findNthInOrder(root, count, N);
    root = remove(root, target->gatorID);

    return root;
}

TreeNode* TreeNode::findMin(TreeNode* node)
{
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode * TreeNode::findMax(TreeNode *node)
{
    TreeNode* current = node;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

TreeNode *TreeNode::leftRotate(TreeNode *root)
{
    TreeNode* newRoot = root->right;
    TreeNode* leftOfNew = newRoot->left;

    newRoot->left = root;
    root->right = leftOfNew;

    //update heights
    root->height = 1 + max((root->left ? root->left->height : 0),
                           (root->right ? root->right->height : 0));

    newRoot->height = 1 + max((newRoot->left ? newRoot->left->height : 0),
                              (newRoot->right ? newRoot->right->height : 0));

    return newRoot;
}

TreeNode *TreeNode::rightRotate(TreeNode *root)
{
    TreeNode* newRoot = root->left;
    TreeNode* rightOfNew = newRoot->right;

    newRoot->right = root;
    root->left = rightOfNew;

    //update heights
    root->height = 1 + max((root->left ? root->left->height : 0),
                           (root->right ? root->right->height : 0));

    newRoot->height = 1 + max((newRoot->left ? newRoot->left->height : 0),
                              (newRoot->right ? newRoot->right->height : 0));

    return newRoot;
}

TreeNode * TreeNode::findNthInOrder(TreeNode *node, int &currCount, int N)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    TreeNode* left = findNthInOrder(node->left, currCount, N);
    if (left != nullptr)
    {
        return left;
    }

    if(currCount == N)
    {
        return node;
    }

    currCount++;

    return findNthInOrder(node->right, currCount, N);
}



