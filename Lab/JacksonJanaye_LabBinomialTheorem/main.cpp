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

float flipCoin(float);
float flipBCoin(float);


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    float stats = 0.0;
    float bStats = 0.0;
    int count = 10000;
    
    for(int i = 0; i < count; i++){
        stats = flipCoin(stats);
    }
    
    stats = stats/count * 100.0;
    
    for(int i = 0; i < count; i++){
        bStats = flipBCoin(bStats);
    }
    
    bStats = bStats/count * 100.0;
    
    cout<<"Chances of getting 3 heads & 1 tail"<<endl;
    cout<<"Flipping normal coin"<<endl;
    cout<<"stats: "<<fixed<<showpoint<<setprecision(2)<<stats<<"%"<<endl;
    cout<<"Flipping 60% biased coin"<<endl;
    cout<<"stats: "<<fixed<<showpoint<<setprecision(2)<<bStats<<"%"<<endl;

    return 0;
}

float flipCoin(float stats){
    int heads = 0;
    int tails = 0;
    int num;    
    
    for(int i = 0; i < 4; i++){
        num = rand()%2;
        if(num == 0)
            heads++;
            
        if(num == 1)
            tails++;
    }

    if(heads == 3 && tails == 1){
        stats++;
    }
    
    return stats;
}

float flipBCoin(float stats){
    int heads = 0;
    int tails = 0;
    int num;    
    
    for(int i = 0; i < 4; i++){
        num = rand()%10;
        if(num <= 5)
            heads++;
            
        if(num > 5)
            tails++;
    }

    if(heads == 3 && tails == 1){
        stats++;
    }
    
    return stats;
}

