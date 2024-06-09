/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on April 20th, 2024, 6:23 PM
 */

//System Level Libraries
#include <cstdlib>      //Random Number Generator, Setting seed, etc....
#include <ctime>        //Time
#include <cstring>
#include<iostream>      //Output/input library
#include<iomanip>       //Formatting Library
#include<list>          //list library
#include<map>           //map library
#include<queue>         //queue library
#include<set>           //set library
#include<stack>         //stack library
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
queue<card> setDeck();
map<string, int> setMap();
unordered_set<string> setName();
void playGame(queue<card>, map<string, int>);
//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char choice;     //player choice
    bool play;       //player play or not play
    map<string, int>value; //value of cards
    queue<card> cards; //shuffled cards 
    
    //Initialize Variables
    play = true;        //player initially play
 
    //Map the inputs/known to the outputs
    cout<<setw(9)<<"Welcome to BlackJack"<<endl;
    cout<<setw(11)<<"What would you like to do"<<endl;
    cout<<setw(9)<<"Play (p) or quit(q)"<<endl;
    cin>>choice;
    if(choice == 'p' || choice =='P'){
        value = setMap();   //set map key and values
        cards=setDeck();  //set deck of cards
        playGame(cards, value);
    }
    
    //Display the outputs
    cout<<"Thank you for playing BlackJack";
    
    //Exit the program
    return 0;
}

void playGame(queue<card> cards, map<string, int>value){
    char choice;   //player choice
    map<string, int>val = value;  //map of faces to their values
    int pTotal, dTotal;           //Total value of dealt cards
    stack<card> pMove;            //player moves
    stack<card> dMove;            //dealer moves
    queue<card> deck = cards;     //deck of cards
    card temp1, temp2, 
            temp3, temp4;     //dealt cards
    bool play;                    //player play or not play
    temp3.face, temp4.face ="";
    temp3.suit, temp4.suit ="";
    
    do{
        temp3.face, temp4.face="";
        
        //player cards
        if(deck.empty())//check deck
            deck = setDeck();
        temp1 = deck.front();
        deck.pop();
        if(deck.empty())//check deck
            deck = setDeck();
        temp2 = deck.front(); 
        deck.pop();
        //display player cards
        cout<<"\nYour first two cards are:"<<endl;
        cout<<temp1.face<<" of "<<temp1.suit<<endl;
        cout<<setw(11)<<"&"<<endl;
        cout<<temp2.face<<" of "<<temp2.suit<<endl;
        //total of cards dealt
        if(temp1.face.compare("ace")==0 || temp2.face.compare("ace") == 0){//aces are a special case
            if(temp1.face.compare("ace")==0){
                pTotal = 11 + val[temp2.face];
                temp3.face="ace";
            }
            else if(temp2.face.compare("ace") == 0){
                pTotal = 11 + val[temp1.face];
                temp3.face="ace";
            }
        }
        else
            pTotal = val[temp1.face] + val[temp2.face];
        cout<<"Player:"<<pTotal<<endl;
        
        if(pTotal == 21){//check for win
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//if not exit game
                play = false;
                break;
            }
        }
        else if(pTotal > 21){//check if player lose
            cout<<"\nBUST"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//if not exit game
                play = false;
                break;
            }
        }
        
        //dealer cards
        if(deck.empty())//check deck
            deck = setDeck();
        temp1 = deck.front();
        deck.pop();
        if(deck.empty())//check deck
            deck = setDeck();
        temp2 = deck.front(); 
        deck.pop();
        //display dealer cards
        cout<<"\nDealer's first two cards are:"<<endl;
        cout<<temp1.face<<" of "<<temp1.suit<<endl;
        cout<<setw(11)<<"&"<<endl;
        cout<<temp2.face<<" of "<<temp2.suit<<endl;
        //total of cards dealt
        if(temp1.face.compare("ace")==0 || temp2.face.compare("ace") == 0){//aces are a special case
            if(temp1.face.compare("ace")==0){
                dTotal = 11 + val[temp2.face];
                temp4.face="ace";
            }
            else if(temp2.face.compare("ace") == 0){
                dTotal = 11 + val[temp1.face];
                temp4.face="ace";
            }
        }
        else
            dTotal = val[temp1.face] + val[temp2.face];
        cout<<"dealer:"<<dTotal<<endl;
            
        
        if(dTotal == 21){//check dealer win
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"The dealer won"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game
                play = false;
                break;
            }
        }
        else if(dTotal > 21){//check if dealer loose
            cout<<"\nThe dealer bust"<<endl;
            cout<<"YOU WIN"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game
                play = false;
                break;
            }
        }
        
        do{//hit player with more  cards until they bust, win, or do not want more
            cout<<"\nWould you like to hit? (y or n)";
            cin>>choice;
            if(choice == 'y'){//check if player hit
                if(deck.empty())//check deck
                    deck = setDeck();
                temp1 = deck.front();
                deck.pop();
                //display card
                cout<<"\nNext card is"<<endl;
                cout<<temp1.face<<" of "<<temp1.suit<<endl;
                pTotal += val[temp1.face];
                cout<<"Player:"<<pTotal<<endl;
            }
            if(pTotal > 21 && temp3.face.compare("ace")==0){
                pTotal -= 10;
                temp3.face = "";
                cout<<"Player:"<<pTotal<<endl;
                continue;
            }
            else if(pTotal >= 21)//check for bust or blackjack
                break;
        }while(choice == 'y');
        if(pTotal == 21){//check for black jack
            temp3.face="";
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game
                play = false;
                break;
            }
        }
        else if(pTotal > 21){//check for bust
            temp3.face="";
            cout<<"\nBUST"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game
                play = false;
                break;
            }
        }
        else if(pTotal < 21){//dealer's turn
            while(dTotal < 18){//if 18 dealer automatically stops hitting
                if(deck.empty())//check deck
                    deck = setDeck();
                temp1 = deck.front();
                deck.pop();
                //display cards
                cout<<"\nDealer's next card is "<<endl;
                cout<<temp1.face<<" of "<<temp1.suit<<endl;
                dTotal+= val[temp1.face];
                cout<<"dealer:"<<dTotal<<endl;
                
                if(dTotal > 21 && temp4.face.compare("ace")==0){
                    dTotal -= 10;
                    temp4.face = "";
                    cout<<"dealer:"<<dTotal<<endl;
                    continue;
                }   
            }
            temp4.face="";
        }
        if(dTotal == 21){//check dealer win
            temp4.face="";
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"The dealer won"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game
                play = false;
                break;
            }
        }
        else if(dTotal > 21){//check dealer bust
            temp4.face="";
            cout<<"\nThe dealer bust"<<endl;
            cout<<"YOU WON"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game
                play = false;
                break;
            }
        }
        
        if(dTotal < 21 && pTotal < 21){//determine winner
            if(dTotal == pTotal)//if neither win
                cout<<"\nDraw"<<endl;
            else if(dTotal > pTotal)//dealer winner if higher
                cout<<"\nThe dealer won this hand"<<endl;
            else//player winner if lower
                cout<<"\nYou won this hand"<<endl;
        }
        temp3.face,temp4.face="";
        
        cout<<"Would you still like to play? (y or n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')//check if player still plays
            play = true;
        else//exit game
            play = false;
    }while(play);
    
    
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
    return temp;
}

queue<card> setDeck(){
    //display output
    cout<<"Shuffling the cards"<<endl;
    //declare variables
    card insrt;
    queue<card> temp;
    list<card> diamond; 
    list<card> clubs;
    list<card> hearts;
    list<card> spades;
    int num;
    
    //initialize variables
    diamond = setCard("Diamonds"); //set list of diamond cards
    clubs = setCard("Clubs");      //set list of club cards
    hearts = setCard("Hearts");    //set list of heart cards
    spades = setCard("Spades");    //set list of spade cards
    
    
    do{//add to deck until all lists are empty
        num = rand()%4; //generate random number to pull from random deck
        if(num == 0 && !diamond.empty()){//pull from diamond
            temp.push(diamond.front());
            diamond.pop_front();
        }
        else if(num == 1 && !clubs.empty()){//pull from clubs
            temp.push(clubs.front());
            clubs.pop_front();
        }
        else if(num == 2 && !hearts.empty()){//pull from hearts
            temp.push(hearts.front());
            hearts.pop_front();
        }
        else if(num == 3 && !spades.empty()){//pull from spades
            temp.push(spades.front());
            spades.pop_front();
        } 
    }while(!diamond.empty() && !clubs.empty() && !hearts.empty() && !spades.empty());
    return temp;
}

map<string, int> setMap(){
    //declare and initialize map
    //set key to value
    map<string, int> value;
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
    
    return value;
}

unordered_set<string> setName(){
    //declare variables
    unordered_set<string> names;
    int num;
    
    //initialize variables
    int size = 13;
    bool set = false;
    int select[size];
    
    //add randomize numbers 0-12
    //shuffle
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
    
    //add card based on array of random numbers
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

