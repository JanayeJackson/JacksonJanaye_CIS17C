/* 
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  Insert and search binary tree analysis
 */

//System Libraries
#include <cstdlib>      //Random Number Generator, Setting seed, etc....
#include <ctime>        //Time
#include<iostream>
#include<algorithm>
using namespace std;
 
//User Libraries
#include "AVLTree.h"

//Global Constants

//Execution Begins Here!
int main(){
    srand(static_cast<unsigned int>(time(0)));
    
    AVLTree avl;
    string f = "";
    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 3; j++){     
            int t = rand()%26+65;
            f += static_cast<char>(t);
        }
        avl.root = avl.insert(avl.root, f);
        f = "";
    }
    for(int j = 0; j < 3; j++){     
        int t = rand()%26+65;
        f += static_cast<char>(t);
    }
    //avl.root=avl.insert(avl.root, f);
    BNTnode *temp = avl.search(avl.root, f);
    if(temp != NULL)
        cout<<f<<" was found after searching "<<avl.count<<" nodes"<<endl;
    else
        cout<<f<<" was not found after searching "<<avl.count<<" nodes"<<endl;
    
    //Exit stage right!
    return 0;
}