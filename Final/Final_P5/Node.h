/* 
 * File:   Node.h
 * Author: Janaye Jackson
 *
 * Created on May 28, 2024, 1:32 AM
 */

#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

// Node class to define the structure of the node
class Node {
public:
    string data;
    Node *left, *right;
    // Parameterized Constructor
    Node(string val){
        data = val;
        left = right = NULL;
    }
};


#endif /* NODE_H */

