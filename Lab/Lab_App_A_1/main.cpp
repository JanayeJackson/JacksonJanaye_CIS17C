/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on 03/05/2023 10:30 AM
 * Purpose: Implementing Summation Series
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
int SumSrs(int, int, int);   //Evaluating Summation Series using iteration
int SumFrml(int, int, int);   //Evaluating Summation Series using a formula

//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    
    //Declare Variables
    int c, n, m;
    
    //Initialize Variables
    
    //Map the inputs/known to the outputs
    cout<<"Input the variable c, n and m, to calculate a summation series:"<<endl;
    cin>>c>>n>>m;
    
    //Display the outputs
    cout<<"Summation Series using iteration: "<<SumSrs(c, n, m)<<endl;
    cout<<"Summation Series using a Formula: "<<SumFrml(c, n, m)<<endl;
    
    //Exit the program

    return 0;
}

int SumSrs(int c, int n, int m){
    int sum = 0; 
    
    for(int i = m; i <= n; i++){
        sum += c;
    }
    
    return sum;
}

int SumFrml(int c, int n, int m){
    
    int sum = c * (n - m + 1);
    return sum;
    
}

