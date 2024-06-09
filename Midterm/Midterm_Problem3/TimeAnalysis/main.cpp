/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 */

//System Libraries
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
using namespace std::chrono;

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
    int beg, end;
    high_resolution_clock::time_point t1, t2;
    int size = 1000;
    Object a(3),b(4);
    SimpleVector<Object> svp(a);
    SimpleVectorPush<Object> svpE(a);
    SimpleVectorList<Object> svpL(a);
    
    //Map inputs to outputs
    //Push an Object and printout the last object
    svp.push(b);
    svpE.push(b);
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //record time
    t1 = high_resolution_clock::now();
    for(int i=0;i<size;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    t2 = high_resolution_clock::now();
    duration<double, std::milli> sP = t2 - t1;
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //record time
    t1 = high_resolution_clock::now();
    for(int i=0;i<size;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svpE.push(c);
    }
    t2 = high_resolution_clock::now();
    duration<double, std::milli> sPE = t2 - t1;
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //record size
    t1 = high_resolution_clock::now();
    for(int i=0;i<size;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svpL.push(c);
    }
    svpL.push(b);
    t2 = high_resolution_clock::now();
    duration<double, std::milli> sPL = t2 - t1;
    
    cout<<"Time Analysis of Push Method"<<endl;
    cout<<"All using N =  "<<size<<endl;
    cout<<"Simple Vector using arrays time analysis = "<<sP.count()<<" milliseconds"<<endl;
    cout<<"Optimized Simple Vector using arrays time analysis = "<<sPE.count()<<" milliseconds"<<endl;
    cout<<"Simple Vector implemented with a Linked List time analysis = "<<sPL.count()<<" milliseconds"<<endl;
    
    if(sP < sPE && sP < sPL)
        cout<<"Simple Vector has the fastest time analysis"<<endl;
    else if(sPE < sP && sPE < sPL)
        cout<<"Optimized Simple Vector has the fastest time analysis"<<endl;
    else
        cout<<"Simple Vector with LinkedList has the fastest time analysis"<<endl;
   
    
    //Exit
    return 0;
}