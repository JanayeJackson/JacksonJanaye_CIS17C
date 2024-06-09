/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on April 19th, 2024, 6:24 PM
 */

//System Level Libraries
#include <cstdlib>  //Random Number Generator, Setting seed, etc....
#include <ctime>    //
#include<iostream>  //Formatting Library
#include<iomanip>
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
queue<card> setDeck(list<card> D, list<card> C, list<card> H, list<card> S);
map<string, int> setMap();
unordered_set<string> setName();
void playGame(queue<card>, map<string, int>);
//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char choice;
    bool play;
    list<card> diamond;  //list of diamond cards
    list<card> hearts;   //list of heart cards
    list<card> clubs;   //list of club cards
    list<card> spades;  //list of spade cards
    map<string, int>value; //value of cards
    queue<card> cards; //shuffled cards 
    
    //Initialize Variables
    play = true;
    value = setMap();   //set map key and values
    
    diamond = setCard("Diamonds"); //set list of diamond cards
    clubs = setCard("Clubs");      //set list of club cards
    hearts = setCard("Hearts");    //set list of heart cards
    spades = setCard("Spades");    //set list of spade cards
    
    cards=setDeck(diamond, clubs, hearts, spades);  //set deck of cards
 
    
    //Map the inputs/known to the outputs
    cout<<setw(9)<<"Welcome to BlackJack"<<endl;
    cout<<setw(11)<<"What would you like to do"<<endl;
    cout<<setw(9)<<"Play (p) or quit(q)"<<endl;
    cin>>choice;
    if(choice == 'p' || choice =='P'){
        playGame(cards, value);
    }
    
    //Display the outputs
    cout<<"Thank you for playing BlackJack";
    
    //Exit the program

    return 0;
}

void playGame(queue<card> cards, map<string, int>value){
    char choice;
    map<string, int>val = value;
    int pTotal, dTotal;
    stack<card> pMove;  //player moves
    stack<card> dMove;  //dealer moves
    queue<card> deck = cards;
    card temp1, temp2;
    bool play;
    
    do{
        //player cards
        temp1 = deck.front();
        deck.pop();
        temp2 = deck.front(); 
        deck.pop();
        cout<<"Your first two cards are:"<<endl;
        cout<<temp1.face<<" of "<<temp1.suit<<endl;
        cout<<setw(11)<<"&"<<endl;
        cout<<temp2.face<<" of "<<temp2.suit<<endl;
        
        pTotal = val[temp1.face] + val[temp2.face];
        if(pTotal == 21){
            cout<<"BLACKJACK!!"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        if(pTotal > 21){
            cout<<"BUST"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        
        //dealer cards
        temp1 = deck.front();
        deck.pop();
        temp2 = deck.front(); 
        deck.pop();
        cout<<"Dealer's first two cards are:"<<endl;
        cout<<temp1.face<<" of "<<temp1.suit<<endl;
        cout<<setw(11)<<"&"<<endl;
        cout<<temp2.face<<" of "<<temp2.suit<<endl;
        
        dTotal = val[temp1.face] + val[temp2.face];
        if(dTotal == 21){
            cout<<"BLACKJACK!!"<<endl;
            cout<<"The dealer won"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        else if(dTotal > 21){
            cout<<"The dealer bust"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        
        do{
            cout<<"Would you like to hit? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y'){
                temp1 = deck.front();
                deck.pop();
                cout<<"Next card is"<<endl;
                cout<<temp1.face<<" of "<<temp1.suit<<endl;
                pTotal += val[temp1.face];
            }
            if(pTotal >= 21){
                break;
            }
        }while(choice == 'y');
        if(pTotal == 21){
            cout<<"BLACKJACK!!"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        else if(pTotal > 21){
            cout<<"BUST"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        else if(pTotal < 21){
            do{
                temp1 = deck.front();
                deck.pop();
                cout<<"Dealer's next card is "<<endl;
                cout<<temp1.face<<" of "<<temp1.suit<<endl;
                dTotal+= val[temp1.face];
                
            }while(dTotal < 18);
        }
        if(dTotal == 21){
            cout<<"BLACKJACK!!"<<endl;
            cout<<"The dealer won"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        else if(dTotal > 21){
            cout<<"The dealer bust"<<endl;
            cout<<"Would you still like to play? (y or n)"<<endl;
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                play = true;
                continue;
            }
            else
            {
                play = false;
                break;
            }
        }
        
        if(dTotal < 21 && pTotal < 21){
            if(dTotal > pTotal){
                cout<<"The dealer won this hand"<<endl;
            }
            else
                cout<<"You won this had"<<endl;
        }
        
        cout<<"Would you still like to play? (y or n)"<<endl;
        cin>>choice;
        if(choice == 'y' || choice == 'Y'){
            play = true;
        }
        else{
            play = false;
        }
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

queue<card> setDeck(list<card> D, list<card> C, list<card> H, list<card> S){
    card insrt;
    queue<card> temp;
  
    list<card> Ds = D; 
    list<card> Cs = C;
    list<card> Hs = H;
    list<card> Ss = S;
    
    int num;
    
    do{
        num = rand()%4;
        
        if(num == 0 && !Ds.empty()){
            temp.push(Ds.front());
            Ds.pop_front();
        }
        else if(num == 1 && !Cs.empty()){
            temp.push(Cs.front());
            Cs.pop_front();
        }
        else if(num == 2 && !Hs.empty()){
            temp.push(Hs.front());
            Hs.pop_front();
        }
        else if(num == 3 && !Ss.empty()){
            temp.push(Ss.front());
            Ss.pop_front();
        } 
        
    }while(!Ds.empty() && !Cs.empty() && !Hs.empty() && !Ss.empty());
  
    return temp;
}

map<string, int> setMap(){
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

