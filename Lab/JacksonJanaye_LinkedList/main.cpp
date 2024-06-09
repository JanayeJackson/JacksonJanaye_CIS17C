/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Linked from first principles
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "LnkdLst.h"
//#include "Link.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    
    //Declare variables
    LnkdLst link;
    Link *addF = new Link;
    Link *addB = new Link;
    Link *remove = new Link;
    addF->data = 18;
    addB->data=13;
    
    
    //Printing all the data elements in the linked list
    link.prntLst();
    
    //Add Element to front of list
    cout<<"\nAfter adding element to the front:"<<endl;
    link.pshFrnt(addF);
    link.prntLst();
    
    //Add Element to back of list
    cout<<"\nAfter adding element to the back:"<<endl;
    link.pshBack(addB);
    link.prntLst();
    
    //Remove element from front of list
    cout<<"\nRemoving element from the front:"<<endl;
    remove = link.popFrnt();
    cout<<"Removed Data: "<<remove->data<<endl;
    cout<<"\nNew List"<<endl;
    link.prntLst();
    
    //Remove element from back of list
    cout<<"\nRemoving element from the back:"<<endl;
    remove = link.popBack();
    cout<<"Removed Data: "<<remove->data<<endl;
    cout<<"\nNew List"<<endl;
    link.prntLst();
    
    //Exit stage right
    return 0;
}

