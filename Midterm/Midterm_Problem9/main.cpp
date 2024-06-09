/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on May 13th, 2024, 10:35 AM
 * Purpose: Create power function using recursion with
 *  O(n) and O(ln n)
 */

//System Level Libraries

#include <iostream>  //Input-Output Library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units

//Function Prototypes
int powN(int, int);
int powLnN(int, int);


//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    
    //Declare/Initialize  Variables
    int x = 2, n = 8;
    
    //Display the outputs
    cout<<"Power function y(n) = O(n)"<<endl;
    for(int i = 0; i < n; i++)
        cout<<powN(x, i)<<endl;
    cout<<"Power function y(n) = O(ln n)"<<endl;
    for(int i = 0; i < n; i++)
        cout<<powLnN(x, i)<<endl;
    //Exit the program

    return 0;
}

//recursive function with O(n)
int powN(int x, int n){
    if(n == 0) //power 0 always = 1, base case
        return 1;
    else //multiply x while n is not 0
        return x * powN(x, n-1);
}

//recursive function with O(ln n)
int powLnN(int x, int n){
    if (n == 0) //power 0 always = 1, base case
        return 1;
    //call to function once
    int powLN = powLnN( x, n/2 ); //fraction of n give O(ln n)
    if (n%2 == 1) //odd function returns
        return x * powLN * powLN;
    else //even function
        return powLN * powLN;
}   

