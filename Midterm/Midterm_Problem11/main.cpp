/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on May 13th, 2024, 7:23 PM
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
float recC(float);
float recS(float);

//Execution begins here!
int main(int argc, char** argv) {
    /*
     * tolerance = 10^6
     * increase by 0.1f
     * C(x) = 1/x + x/6 S(x) = 1 + x^2/2
     * C(2x) = 1/2C(x)S(x) and S(2x) = (C^2(x)S^2(x))/(C^2(x)-S^2(x))
     */
    
    //-1 to 0
    for (float x=-atan(1.0); x<=0; x+=0.1f){
        cout<<"x = "<<x<<endl;
        cout<<"C(2x) = "<<recC(x)<<"\n     and"<<endl;
        cout<<"S(2x) = "<<recS(x)<<endl<<endl;
    }
    //0 to 1
    for (float x=0; x<atan(1.0); x+=0.1f){
        cout<<"x = "<<x<<endl;
        cout<<"C(2x) = "<<recC(x)<<"\n     and"<<endl;
        cout<<"S(2x) = "<<recS(x)<<endl<<endl;
    }
    //Exit the program

    return 0;
}

float recC(float x){
    //Base condition
    float tol = 1e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x) < tol)
        return 1/x + x/6;
    //Recursive Representation
    return 0.5* recC(x/2) * recS(x/2);
}

float recS(float x){
    //Base condition
    float tol = 1e-6f;//Tolerance of 6 decimal, small x approximation
    if(abs(x) < tol)
        return 1 + x*x/2;
    //Recursive Representation
    float a = recC(x/2);
    float b = recS(x/2);
    return (a * a * b * b)/(a*a - b*b);
    
}






