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

#include "AVLTree.h"

using namespace std;

int main(){
    int numCommands = 0;
    vector<string> commandLines;

    ifstream inputFile("../test-io/input-files/1.txt");
    if(inputFile.is_open())
    {
        inputFile >> numCommands;
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

//    int count = 0;
//
//    while(count < numCommands)
//    {
//        // execute commands
//    }


	return 0;
}
