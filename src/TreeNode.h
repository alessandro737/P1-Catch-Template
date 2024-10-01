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
    int height = 0;
    string name;
    TreeNode *left;
    TreeNode *right;

public:
    // constructor & destructor
    TreeNode(int x, string n) : gatorID(x), height(0), name(n), left(nullptr), right(nullptr){}

    // functionalities
    TreeNode* search(TreeNode* root, int key);
    TreeNode* search(TreeNode* root, string val);
    TreeNode* insert(TreeNode* root, int key, string val);
    TreeNode* remove(TreeNode* root, int key);
    //Todo:
    void printInorder(TreeNode* root);
    void printPreorder(TreeNode* root);
    void printPostorder(TreeNode* root);
    void printLevelCount(TreeNode* root);
    TreeNode* removeInorderN(TreeNode* root, int N);

    //helpers
    int getGatorID() const;
    string getName();
    TreeNode* findMin(TreeNode* node);
    TreeNode* findMax(TreeNode* node);
    TreeNode* leftRotate(TreeNode* root);
    TreeNode* rightRotate(TreeNode* root);
};


#endif //P1_GATORAVL_TREENODE_H
