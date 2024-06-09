/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on March 27, 2024, 10:35 AM
 * Purpose: Calculate Temperature Linear Curve
 *          fit using data from lecture 
 */

//System Level Libraries

#include <iostream>  //Input-Output Library
#include <iomanip>
#include <fstream>
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units

//Function Prototypes
float cSlope(int[], float[], float &, int);
void readIn(fstream &, int[], float[], int);

//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    
    //Declare Variables
    fstream txtFile;
    float slope, intcpt;
    const int size = 37;
    int frnht[size];
    float error[size];
    
    
    //Initialize Variables
     txtFile.open("LabData.txt",ios::in|ios::out);
    
    //Map the inputs/known to the outputs
     readIn(txtFile, frnht, error, size);
     slope = cSlope(frnht, error, intcpt, size);
    
    //Display the outputs
     cout<<"The slope of the file data is: "<<slope<<endl;
     cout<<"The intercept of the file data is: "<<intcpt<<endl;
    
    //Exit the program
     txtFile.close();

    return 0;
}

void readIn(fstream &txt, int f[], float e[], int size)
{
    for(int i = 0; i < size; i++){
        txt>>f[i]>>e[i];
    }
}

float cSlope(int f[], float e[], float &intcpt, int size){
    float sumX, sumY, sumX2, sumXY, yPrime, slope;
    
    for(int i = 0; i < size; i++)
    {
        sumX += f[i];
        yPrime = ((5/9.0) * f[i])+ (-32 * 5 / 9.0) + e[i];
        sumY += yPrime;
        sumX2 += f[i] *f[i];
        sumXY += f[i] * yPrime;
    }
 
    
    slope = (sumX * sumY - size* sumXY)/(sumX * sumX - size * sumX2);
    intcpt = (sumY - slope*sumX)/size;
    return slope;
}