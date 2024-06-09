/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 * Created on May 11, 2024, 8:15 PM
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Library
#include <ctime>      //Time Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
bool chck1(int, int, int, int);
bool chck2(int, int, int, int);
bool chck3(int, int, int, int);
bool chck4(int, int, int, int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int value;
    int size = 13;
    int count = 10000;
    int cards[size];
    int card1, card2, card3, card4;
    float pair1,pair2,throfk, fourofk;
    //Initialize Variables
    pair1 = 0;
    pair2 = 0;
    throfk = 0;
    fourofk = 0;
    
    //Map the inputs/known to the outputs
    for(int i = 0; i < size; i++)
        cards[i] = i+1;
    
    for(int i = 0; i < count; i++){
        card1 = cards[rand()%13];
        card2 = cards[rand()%13];
        card3 = cards[rand()%13];
        card4 = cards[rand()%13];
        if(chck1(card1, card2, card3, card4))
            pair1++;
    }
    
    for(int i = 0; i < count; i++){
        card1 = cards[rand()%13];
        card2 = cards[rand()%13];
        card3 = cards[rand()%13];
        card4 = cards[rand()%13];
        if(chck2(card1, card2, card3, card4))
            pair2++;
    }
    
    for(int i = 0; i < count; i++){
        card1 = cards[rand()%13];
        card2 = cards[rand()%13];
        card3 = cards[rand()%13];
        card4 = cards[rand()%13];
        if(chck3(card1, card2, card3, card4))
            throfk++;
    }
    
    for(int i = 0; i < count; i++){
        card1 = cards[rand()%13];
        card2 = cards[rand()%13];
        card3 = cards[rand()%13];
        card4 = cards[rand()%13];
        if(chck4(card1, card2, card3, card4))
            fourofk++;
    }
    
    pair1 = pair1/count * 100.0;
    pair2 = pair2/count *100.0;
    throfk = throfk/count * 100.0;
    fourofk = fourofk/count * 100.0;
    
    //Display the outputs
    cout<<"Probability of 1 pair is "<<pair1<<endl;
    cout<<"Probability of 2 pairs is "<<pair2<<endl;
    cout<<"Probability of 3 of a kind is "<<throfk<<endl;
    cout<<"Probability of 4 of a kind is "<<fourofk<<endl;
    
    
    //Exit the program

    return 0;
}

bool chck1(int one, int two, int thr, int four){
    if(one == two && one != thr && one != four)
        return true;
    if(one == thr && one != two && one != four)
        return true;
    if(one == four && one != two && one != thr)
        return true;
    if( one == two && two != thr && two != four)
        return true;
    if(two == thr && two != one && two != four)
        return true;
    if(two == four && one != two && two != thr)
        return true;
    if(one == thr && two != thr && thr != four)
        return true;
    if(thr == two && one != thr && thr != four)
        return true;
    if(thr == four && thr != two && one != thr)
        return true;
    if(one == four && four != thr && two != four)
        return true;
    if(four == thr && one != four && two != four)
        return true;
    if(two == four && one != four && four != thr)
        return true;
    
    
    
    return false;
}

bool chck2(int one, int two, int thr, int four){
    if(one == two && thr == four && thr != two)
        return true;
    if(one == thr && two == four && thr != two)
        return true;
    if(one == four && two == thr && one != two)
        return true;
    return false;
}

bool chck3(int one, int two, int thr, int four){
    if(one == two && one == thr && one != four)
        return true;
    if(one == thr && one == four && one != two)
        return true;
    if(one == four && one == two && one != thr)
        return true;
    if(two == thr && two == four && two!= one)
        return true;
    return false;
}

bool chck4(int one, int two, int thr, int four){
    if(one == two && thr == four && two == thr)
        return true;
    return false;
}