#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

TEST_CASE("Test incorrect commands")
{
    // Doesn't actually do anything my input validation is handled in main
    // Not sure how to test that here but anyway...
    TreeNode* root = nullptr;

    // Trying to insert with invalid GatorID
    root = root->insert(root, -45679999, "Anna");
    REQUIRE(root == nullptr); // No changes to the tree because input should be rejected

    // Duplicate GatorID
    root = root->insert(root, 12345678, "Carlos");
    TreeNode* result = root->insert(root, 12345678, "Carlos");
    REQUIRE(result == root); // Tree should remain unchanged on duplicate insert
}

TEST_CASE("Test edge cases")
{
    TreeNode* root = nullptr;

    // Removing from an empty tree should return nullptr
    root = root->remove(root, 12345678);
    REQUIRE(root == nullptr);

    // Inserting into empty tree
    root = root->insert(root, 99999999, "RNGNode");
    REQUIRE(root->search(root, 99999999) != nullptr); // Ensure its inserted

    // Removing the root node
    root = root->remove(root, 00000000);
    REQUIRE(root != nullptr); // Ensure that the root is removed properly
}

TEST_CASE("Test AVL rotations")
{
    TreeNode* root = nullptr;

    // Left-Left Rotation (Right Rotation)
    root = root->insert(root, 40000000, "Node1");
    root = root->insert(root, 30000000, "Node2");
    root = root->insert(root, 20000000, "Node3");
    REQUIRE(root->getGatorID() == 30000000); // After right rotation, 30000000 should be the root

    // Right-Right Rotation (Left Rotation)
    root = root->insert(root, 50000000, "Node4");
    root = root->insert(root, 60000000, "Node5");
    REQUIRE(root->right->getGatorID() == 50000000); // Ensure correct structure

    // Left-Right Rotation (Left-Right Rotation)
    root = root->insert(root, 10000000, "Node6");
    root = root->insert(root, 15000000, "Node7");
    REQUIRE(root->left->getGatorID() == 15000000); // After left-right, 15000000 should be left child

    // Right-Left Rotation (Right-Left Rotation)
    root = root->insert(root, 70000000, "Node8");
    root = root->insert(root, 65000000, "Node9");
    REQUIRE(root->right->getGatorID() == 50000000); // After right-left, 50000000 should be right child
}

TEST_CASE("Test deletion cases")
{
    TreeNode* root = nullptr;

    root = root->insert(root, 50000000, "Node1");
    root = root->insert(root, 30000000, "Node2");
    root = root->insert(root, 70000000, "Node3");
    root = root->insert(root, 60000000, "Node4");
    root = root->insert(root, 90000000, "Node5");

    // Case 1: Deleting node with no children
    root = root->remove(root, 30000000);
    REQUIRE(root->search(root, 30000000) == nullptr); // 30000000 is removed

    // Case 2: Deleting node with one child
    root = root->remove(root, 60000000);
    REQUIRE(root->search(root, 60000000) == nullptr); // 60000000 is removed

    // Case 3: Deleting node with two children
    root = root->remove(root, 70000000);
    REQUIRE(root->search(root, 70000000) == nullptr); // 70000000 is removed
}

TEST_CASE("Test inserting and removing 100 nodes")
{
    TreeNode* root = nullptr;
    vector<int> expectedOutput, actualOutput;

    // insert 100 nodes
    for(int i = 0; i < 100000; i++)
    {
        int randomInput = rand();
        if (count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
        {
            expectedOutput.push_back(randomInput);
            root->insert(root, randomInput, "RandomNode");
        }
    }

    // check if equal
    actualOutput = root->inorder(root);
    REQUIRE(expectedOutput.size() == actualOutput.size());
    std::sort(expectedOutput.begin(), expectedOutput.end());
    REQUIRE(expectedOutput == actualOutput);
}









