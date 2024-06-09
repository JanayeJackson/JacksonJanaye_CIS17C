/* 
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  Example of using rotations to balance a tree
 */

//System Libraries
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
 
//User Libraries
#include "AVLTree.h"

//Global Constants

//Function Prototypes
void menu();

//Execution Begins Here!
int main(){
    //set random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    int size, item;
    AVLTree avl;
    size = 10;
    
    for(int i = 0; i < size; i++){
        item  = rand()%size;
        avl.root = avl.insert(avl.root, item);
    }
    cout<<"In-order Traversal:"<<endl;
    avl.inorder(avl.root);
    cout<<endl;
   
    cout<<"Pre-order Traversal:"<<endl;
    avl.preorder(avl.root);
    cout<<endl;
   
    cout<<"Post-order Traversal:"<<endl;
    avl.postorder(avl.root);    
    cout<<endl;
    
    //Exit stage right!
    return 0;
}
