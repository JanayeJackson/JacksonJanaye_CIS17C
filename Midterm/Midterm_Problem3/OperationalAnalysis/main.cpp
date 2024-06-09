/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

//User Libraries
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes
#include "SimpleVectorPush.h" //Simple Vector only works with Classes
#include "SimpleVectorList.h"

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //declare/initialize variables
    int size = 100;
    int sTotal, eTotal, lTotal;
    Object a(3);
    SimpleVector<Object> svp(a);
    SimpleVectorPush<Object> svpE(a);
    SimpleVectorList<Object> svpL(a);
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //record operations
    for(int i=0;i<size;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //record operations
    for(int i=0;i<size;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svpE.push(c);
    }
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //record operations
    for(int i=0;i<size;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svpL.push(c);
    }
    
    //Get total operations
    sTotal = svp.Ob + svp.Oi + svp.Oj + svp.Os;
    eTotal = svpE.Ob + svpE.Oi + svpE.Oj + svpE.Os;
    lTotal = svpL.Ob + svpL.Oi + svpL.Oj + svpL.Os;
    
    //Output Results
    cout<<"Operational Analysis of Push Method"<<endl;
    cout<<"All using N =  "<<size<<endl;
    cout<<"Simple Vector using arrays Operational Analysis"<<endl;
    cout<<"Ob    = "<<svp.Ob<<endl;
    cout<<"Oi    = "<<svp.Oi<<endl;
    cout<<"Oj    = "<<svp.Oj<<endl;
    cout<<"Os    = "<<svp.Os<<endl;
    cout<<"Total = "<<sTotal<<endl;
    cout<<"\nOptimized Simple Vector using arrays Operational Analysis"<<endl;
    cout<<"Ob    = "<<svpE.Ob<<endl;
    cout<<"Oi    = "<<svpE.Oi<<endl;
    cout<<"Oj    = "<<svpE.Oj<<endl;
    cout<<"Os    = "<<svpE.Os<<endl;
    cout<<"Total = "<<eTotal<<endl;
    cout<<"\nSimple Vector implemented with a Linked List Operational Analysis"<<endl;
    cout<<"Ob    = "<<svpL.Ob<<endl;
    cout<<"Oi    = "<<svpL.Oi<<endl;
    cout<<"Oj    = "<<svpL.Oj<<endl;
    cout<<"Os    = "<<svpL.Os<<endl;
    cout<<"Total = "<<lTotal<<endl;
    
    if(sTotal < eTotal && sTotal < lTotal)
        cout<<"Simple Vector has the smallest operational analysis"<<endl;
    else if(eTotal < sTotal && eTotal < lTotal)
        cout<<"Optimized Simple Vector has the smallest operational analysis"<<endl;
    else
        cout<<"Simple Vector with LinkedList has the smallest operational analysis"<<endl;
   
    
    //Exit
    return 0;
}