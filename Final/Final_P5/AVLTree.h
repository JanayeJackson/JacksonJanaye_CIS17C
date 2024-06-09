/* 
 * File:   AVLTree.h
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-AVL-trees/
 * Created on June 4th, 2024
 * Purpose:  A Binary Tree using an AVL balancing technique
 */

#ifndef AVLTREE_H
#define	AVLTREE_H

#include <iostream>
using namespace std;

#include "BNTnode.h"

class AVLTree{
    public:
        BNTnode *root;                   //Root node
        int count = 0;                   //Number of nodes used in search
        int height(BNTnode *);           //Tree height
        int diff(BNTnode *);             //Difference of right/left subtrees
        BNTnode *rr_rotation(BNTnode *); //Right-Right rotation
        BNTnode *ll_rotation(BNTnode *); //Left-Left   rotation
        BNTnode *lr_rotation(BNTnode *); //Left-Right  rotation
        BNTnode *rl_rotation(BNTnode *); //Right-Left  rotation
        BNTnode* balance(BNTnode *);     //Balance subtrees with diff > 1
        BNTnode* insert(BNTnode *, string);//Insert and balance the tree
        BNTnode* search(BNTnode *, string);//Search for key in binary tree
        AVLTree(){root = NULL;}          //Constructor
};

//Height of AVL Sub Trees
int AVLTree::height(BNTnode *temp){
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
//Height Difference of AVL Sub Trees
int AVLTree::diff(BNTnode *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
//Right-Right Rotations of Sub Trees
BNTnode *AVLTree::rr_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

//Left-Left Rotations of Sub Trees
BNTnode *AVLTree::ll_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
//Left-Right Rotations of Sub Trees
BNTnode *AVLTree::lr_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
//Right-Left Rotations of Sub Trees
BNTnode *AVLTree::rl_rotation(BNTnode *parent){
    BNTnode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
//Balancing of Sub Trees
BNTnode *AVLTree::balance(BNTnode *temp){
    int bal_factor = diff (temp);
    if (bal_factor > 1){
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }else if (bal_factor < -1){
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

//Insert the Data into the Sub Trees
BNTnode *AVLTree::insert(BNTnode *root, string value){
    if (root == NULL){
        root = new BNTnode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value.compare(root->data) < 0){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value >= root->data){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

//Search for key in binary tree
BNTnode *AVLTree::search(BNTnode* root, string key){
// Base Cases: root is null or key is present at root
if (root == NULL || root->data.compare(key) == 0){
    count++;
    return root;
}
// Key is greater than root's key
if (root->data.compare(key) < 0){
    count++;
    return search(root->right, key);
}
// Key is smaller than root's key
    count++;
    return search(root->left, key);
}

#endif	/* AVLTREE_H */
