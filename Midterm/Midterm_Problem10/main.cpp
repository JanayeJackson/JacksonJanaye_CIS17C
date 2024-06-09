/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on May 13th, 2024, 1:30 PM
 * Purpose: Recursive function 
 *             
 */

//System Level Libraries
#include <cmath>
#include <iostream>  //Input-Output Library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units

//Function Prototypes
float rFnctn(float);

//Execution begins here!
int main(int argc, char** argv) {
    /*
     * tolerance = 10^6
     * increase by 0.1f
     * g(x) = x - x^3/6
     * g(2x) = 2g(x)/(1 + g^2(x) 
     * -1<x<1
     */
    
    //-1 to 0
    for (float x=-1.0; x<=0; x+=0.1f)
        cout<<"x = "<<x<<"| g(2x) = "<<rFnctn(x)<<endl;
    //0 to 1
    for (float x=0; x<1.1; x+=0.1f)
        cout<<"x = "<<x<<"| g(2x) = "<<rFnctn(x)<<endl;
    //Exit the program

    return 0;
}

float rFnctn(float x){
    //converted g(2x) to g(x) = F(g(x/2))
    //to simplify function
    //Base condition
    float tol= 1e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x)< tol) 
        return x-x*x*x/6;
    //Recursive Representation
    float a= rFnctn(x/2);
    return 2*a/(1+a*a);
}




