//
// Created by Alessandro Giusti on 9/16/2024.
//

#ifndef P1_GATORAVL_AVLTREE_H
#define P1_GATORAVL_AVLTREE_H
#include <string>
using namespace std;

class AVLTree {
private:
    int gatorID = 0;
    string name;
    AVLTree *left;
    AVLTree *right;

public:
    AVLTree(int x, string n) : gatorID(x), name(n), left(nullptr), right(nullptr){}
    int getGatorID() const;
    string getName();
    AVLTree* searchID(AVLTree* root, int key);
    AVLTree* searchNAME(AVLTree* root, string key);
    AVLTree * insertGator(AVLTree* root, int ID, string n);

};


#endif //P1_GATORAVL_AVLTREE_H
