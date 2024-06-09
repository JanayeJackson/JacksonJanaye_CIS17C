/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on April 23, 2024, 7:47 PM
 */

#include <cstdlib>
#include<ctime>
#include<iomanip>
#include <iostream>

float simFllV(float);


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    float stats = 0.0;
    int count = 10000;
    
    for(int i = 0; i < count; i++){
        stats = simFllV(stats);
    }
    stats = stats/count * 100.0;
    
    cout<<"Simulating Bit Vector 40% Full"<<endl;
    cout<<"5 bits are in full area"<<endl;
    cout<<"stats: "<<fixed<<showpoint<<setprecision(2)<<stats<<"%"<<endl;

    return 0;
}

float simFllV(float stats){
    int full = 0;
    int nFull = 0;
    int num;    
    
    for(int i = 0; i < 5; i++){
        num = rand()%10 + 1;
        if(num <= 4)
            full++;
            
        if(num > 4)
            nFull++;
    }

    if(full == 5){
        stats++;
    }
    
    return stats;
}

