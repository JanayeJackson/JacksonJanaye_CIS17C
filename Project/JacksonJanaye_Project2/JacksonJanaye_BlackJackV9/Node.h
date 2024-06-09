/* 
 * File:   Node.h
 * Author: Janaye Jackson
 *
 * Created on May 28, 2024, 1:32 AM
 */

#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
#include "card.h"
using namespace std;

// Node class to define the structure of the node
struct Node {
    card data;
    struct Node *left;
    struct Node *right;
};


#endif /* NODE_H */

