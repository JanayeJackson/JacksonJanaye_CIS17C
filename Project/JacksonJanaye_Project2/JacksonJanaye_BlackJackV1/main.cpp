/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on April 16th, 2024, 5:16 PM
 */

//System Level Libraries
#include <cstdlib>  //Random Number Generator, Setting seed, etc....
#include <ctime>    //
#include<iostream>  //Formatting Library
#include<list>      //list library
#include<map>       //map library
#include<queue>     //queue library
#include<set>       //set library
#include<stack>     //stack library
#include<unordered_set> //unordered set library

using namespace std;


//User Defined Libraries
#include "card.h"

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units

//Function Prototypes
list<card> setCard(string);
unordered_set<string> setName();

//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    list<card> diamond;  //list of diamond cards
    list<card> hearts;   //list of heart cards
    list<card> clubs;   //list of club cards
    list<card> spades;  //list of spade cards
    map<string, int>value; //value of cards
    queue<card> cards; //shuffled cards 
    
    stack<card> pMove;  //player moves
    stack<card> dMove;  //dealer moves
    
    //Initialize Variables
    value["ace"] = 1;
    value["two"] = 2;
    value["three"] = 3;
    value["four"] = 4;
    value["five"] = 5;
    value["six"] = 6;
    value["seven"] = 7;
    value["eight"] = 8;
    value["nine"] = 9;
    value["ten"] = 10;
    value["jack"] = 10;
    value["queen"] = 10;
    value["king"] = 10;
    
    diamond = setCard("Diamond");
    clubs = setCard("Club");
    hearts = setCard("Heart");
    spades = setCard("Spade");
 
    
    //Map the inputs/known to the outputs
    
    //Display the outputs
    
    //Exit the program

    return 0;
}

list<card> setCard(string suit){
    //declare variables
    list<card> temp;
    card insrt;
    unordered_set<string> face;
    
    //initialize variables
    face=setName();
    unordered_set<string>::iterator itr;
    
    //set each element in the list
    for(itr = face.begin(); itr != face.end();itr++){
        insrt.face = *itr;
        insrt.suit = suit;
        temp.push_front(insrt);
    }
    
    list<card>::iterator itr2;
    for(itr2 = temp.begin(); itr2 != temp.end();itr2++){
        insrt = *itr2;
        cout<<insrt.face;
        cout<<" "<<insrt.suit<<endl;
    }
    return temp;
}

unordered_set<string> setName(){
    unordered_set<string> names;
    int num;
    int size = 13;
    int select[size];
    bool set = false;
    
    select[0] = rand()%13;
    for(int i = 1; i < size; i++){
        do{
            num = rand()%13;
            for(int j = 0; j < i; j++){
                if(num == select[j]){
                    set = false;
                    break;
                }
                else
                    set = true;
            }
        }while(!set);
        select[i] = num;
    }
    
    for(int i = 0; i < size; i++){
       num = select[i];
        switch(num){
            case(0):
                names.insert("ace");
                break;
            case(1):
                names.insert("two");
                break;
            case(2):
                names.insert("three");
                break;
            case(3):
                names.insert("four");
                break;
            case(4):
                names.insert("five");
                break;
            case(5):
                names.insert("six");
                break;
            case(6):
                names.insert("seven");
                break;
            case(7):
                names.insert("eight");
                break;
            case(8):
                names.insert("nine");
                break;
            case(9):
                names.insert("ten");
                break;
            case(10):
                names.insert("jack");
                break;
            case(11):
                names.insert("queen");
                break;
            default:
                names.insert("king");
                break;
        }
    }
    return names;
}

