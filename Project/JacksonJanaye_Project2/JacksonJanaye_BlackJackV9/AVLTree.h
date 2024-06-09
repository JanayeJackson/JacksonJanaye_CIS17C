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

#include "Node.h"

class AVLTree{
    public:
        Node *root;                   //Root node
        int count = 0;                   //Number of nodes used in search
        int height(Node *);           //Tree height
        int diff(Node *);             //Difference of right/left subtrees
        Node *rr_rotation(Node *); //Right-Right rotation
        Node *ll_rotation(Node *); //Left-Left   rotation
        Node *lr_rotation(Node *); //Left-Right  rotation
        Node *rl_rotation(Node *); //Right-Left  rotation
        Node* balance(Node *);     //Balance subtrees with diff > 1
        Node* insert(Node *, card);//Insert and balance the tree
        Node* search(Node *, card);//Search for key in binary tree
        AVLTree(){root = NULL;}          //Constructor
};

//Height of AVL Sub Trees
int AVLTree::height(Node *temp){
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
int AVLTree::diff(Node *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
//Right-Right Rotations of Sub Trees
Node *AVLTree::rr_rotation(Node *parent){
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

//Left-Left Rotations of Sub Trees
Node *AVLTree::ll_rotation(Node *parent){
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
//Left-Right Rotations of Sub Trees
Node *AVLTree::lr_rotation(Node *parent){
    Node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
//Right-Left Rotations of Sub Trees
Node *AVLTree::rl_rotation(Node *parent){
    Node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
//Balancing of Sub Trees
Node *AVLTree::balance(Node *temp){
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
Node *AVLTree::insert(Node *root, card value){
    if (root == NULL){
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value.face.compare(root->data.face) < 0){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value.face.compare(root->data.face) >= 0){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

//Search for key in binary tree
Node *AVLTree::search(Node* root, card key){
// Base Cases: root is null or key is present at root
if (root == NULL || (root->data.face.compare(key.face) == 0 && root->data.suit.compare(key.suit) == 0)){
    count++;
    return root;
}
// Key is greater than root's key
if (root->data.face.compare(key.face) < 0){
    count++;
    return search(root->right, key);
}
// Key is smaller than root's key
    count++;
    return search(root->left, key);
}

#endif	/* AVLTREE_H */

