//
// Created by Alessandro Giusti on 9/16/2024.
//

#ifndef P1_GATORAVL_TREENODE_H
#define P1_GATORAVL_TREENODE_H
#include <string>
#include <vector>

using namespace std;

class TreeNode {
private:
    int gatorID = 0;
    int height = 0;
    string name;
//    TreeNode* left;
//    TreeNode* right;

public:
    // constructor & destructor
    TreeNode(int x, const string& n) : gatorID(x), height(0), name(n), left(nullptr), right(nullptr){}
    ~TreeNode();

    // functionalities
    TreeNode* search(TreeNode* root, int key);
    TreeNode* search(TreeNode* root, const string& val, bool& found);
    TreeNode* insert(TreeNode* root, int key, const string& val);
    TreeNode* remove(TreeNode* root, int key);
    void printInorder(const TreeNode* root, bool& firstPrinted);
    void printPreorder(const TreeNode* root, bool& firstPrinted);
    void printPostorder(const TreeNode* root, bool& firstPrinted);
    void printLevelCount(const TreeNode* root);
    TreeNode* removeInorder(TreeNode* root, int N);

    // helpers
    TreeNode* findMin(TreeNode* node);
    TreeNode* leftRotate(TreeNode* root);
    TreeNode* rightRotate(TreeNode* root);
    TreeNode* findNthInOrder(TreeNode* node, int& currCount, int N);
    int getGatorID();

    // for test.cpp purposes
    std::vector<int> inorder(TreeNode* root);
    TreeNode* left;
    TreeNode* right;
};


#endif //P1_GATORAVL_TREENODE_H
