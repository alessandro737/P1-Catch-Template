/**
 * Name: Project 1: Gator AVL
 * Course: COP3530
 * Class: 12029
 * Author: Alessandro Giusti
 * Date: 9/24/2024
 *
 * Description: Implementation of AVL Tree
 *              to organize UF student accounts
 *              based on GatorIDs. Includes
 *              insertion, deletion, search, and
 *              traversal functionality.
 *
 * Input:   test-io/input-files/N.txt
 *          content parsed for
 *          processing in main
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

#include "TreeNode.h"

using namespace std;

int main() {
    vector<string> commandLines;
    ifstream inputFile("../test-io/input-files/5.txt");

    if(inputFile.is_open())
    {
        int numCommands = 0;
        inputFile >> numCommands;
        inputFile.ignore();
        commandLines.resize(numCommands);
        for(int i = 0; i < numCommands; i++)
        {
            getline(inputFile, commandLines[i]);
        }
        inputFile.close();
    }
    else
    {
        cerr << "Couldn't open input file." << endl;
        inputFile.close();
        return -1;
    }

    regex insertRegex("^insert\\s+\"([a-zA-Z\\s]+)\"\\s+(\\d{8})$");
    regex removeRegex("^remove\\s+(\\d{8})$");
    regex searchIdRegex("^search\\s+(\\d{8})$");
    regex searchNameRegex("^search\\s+\"([a-zA-Z\\s]+)\"$");
    regex removeInorderRegex("^removeInorder\\s+(\\d+)$");
    regex simpleCommandRegex("^print(Inorder|Preorder|Postorder|LevelCount)$");
    smatch matches;

    TreeNode* root = nullptr;
    for(const string& command : commandLines)
    {
        if (regex_match(command, matches, insertRegex)) {
            string name = matches[1].str();
            int id = stoi(matches[2].str());
            // cout << "Inserting: " << name << ", ID: " << id << endl;
            root = root->insert(root, id, name);
        }
        else if (regex_match(command, matches, removeRegex)) {
            string id = matches[1].str();
            // cout << "Removing ID: " << id << endl;
            root = root->remove(root, stoi(id));
        }
        else if (regex_match(command, matches, searchIdRegex)) {
            string id = matches[1].str();
            // cout << "Searching by ID: " << id << endl;
            if(root == nullptr) {
                cout << "unsuccessful" << endl;
            }
            else
            {
                TreeNode* result = root->search(root, stoi(id));
                if (result == nullptr)
                {
                    cout << "unsuccessful" << endl;
                }
            }
        }
        else if (regex_match(command, matches, searchNameRegex)) {
            string name = matches[1].str();
            // cout << "Searching by Name: " << name << endl;
            if(root == nullptr) {
                cout << "unsuccessful" << endl;
            }
            else
            {
                bool found = false;
                root->search(root, name, found);
                if (!found)
                {
                    cout << "unsuccessful" << endl;
                }
            }
        }
        else if (regex_match(command, matches, removeInorderRegex)) {
            int n = stoi(matches[1].str());
            // cout << "Removing Inorder N: " << n << endl;
            root = root->removeInorder(root, n);
        }
        else if (regex_match(command, matches, simpleCommandRegex)) {
            string commandType = matches[1].str();
            bool firstPrinted = false;
            // cout << "Executing " << commandType << " traversal" << endl;
            if (commandType == "Inorder") {
                root->printInorder(root, firstPrinted);
                cout << endl;
            } else if (commandType == "Preorder") {
                root->printPreorder(root, firstPrinted);
                cout << endl;
            } else if (commandType == "Postorder") {
                root->printPostorder(root, firstPrinted);
                cout << endl;
            } else if (commandType == "LevelCount") {
                root->printLevelCount(root);
            }
        }
        else {
            cerr << "unsuccessful" << endl;
        }
    }
    return 0;
}
