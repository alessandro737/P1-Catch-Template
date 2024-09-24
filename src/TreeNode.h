//
// Created by Alessandro Giusti on 9/16/2024.
//

#ifndef P1_GATORAVL_TREENODE_H
#define P1_GATORAVL_TREENODE_H
#include <string>
using namespace std;

class TreeNode {
private:
    int gatorID = 0;
    string name;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int x, string n) : gatorID(x), name(n), left(nullptr), right(nullptr){}
    int getGatorID() const;
    string getName();
    TreeNode* search(TreeNode* root, int key);
    TreeNode* search(TreeNode* root, string val);
    TreeNode* insert(TreeNode* root, int key, string val);
    TreeNode* remove(TreeNode* root, int key);

    //helpers
    TreeNode* findMin(TreeNode *node);
    TreeNode* findMax(TreeNode *node);
};


#endif P1_GATORAVL_TREENODE_H
