/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on May 27th, 2024, 11:11 AM
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
//if user splits their hand
bool split(list<int>&, map<string, int>, queue<card> &, int &, int, card, card, stack<card>&, stack<card>&);                 
list<card> setCard(string);   //add 13 cards of one suit to a list
queue<card> setDeck();        //randomly add 52 cards to a deck
map<string, int> setMap();    //add faces and their values to a map
unordered_set<string> setName(); //set the face and suit of cards
void displayRule();             //display rules of the game           
void playGame(queue<card>, map<string, int>); //Game play
void showPlays(list<int>);   //show the plays of the player               
void stats(stack<card>, stack<card>); //show the stats of all cards drawn
void calcStats(map<string, int>, float&, float&, float&);  //calculate stats
void pStats(float, float, float);  //display stats
void mrgSort(card*,card*,int,int);
void merge(card*, card*, int,int,int);
int recuStats(int, queue<card>&, map<string, int> val);   //recursively create hands

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
    cout<<"Do you need to see the rules"<<endl;
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
        displayRule();
    cout<<setw(11)<<"What would you like to do"<<endl;
    cout<<setw(9)<<"Play (p) or quit(q)"<<endl;
    cin>>choice;
    if(choice == 'p' || choice =='P'){
        value = setMap();   //set map key and values
        cards=setDeck();  //set deck of cards
        playGame(cards, value);
    }
    
    //Display the output
    cout<<"Thank you for playing BlackJack";
    
    //Exit the program
    return 0;
}
//implement game play
void playGame(queue<card> cards, map<string, int>val){
    char choice;   //player choice
    float bust = 0, blckJ = 0, stand = 0;
    list<int> scores;             //list to hold the score from each play
    int pTotal, dTotal;           //Total value of dealt cards
    stack<card> pMove;            //player moves
    stack<card> dMove;            //dealer moves
    queue<card> deck = cards;     //deck of cards
    card temp1, temp2, 
            temp3, temp4;         //dealt cards
    bool play;                    //player play or not play
    bool bet = false;             //Whether player wants to bet or not
    int bMoney = 0;             //Amount player bets with
    int pMoney = 100;        //Amount player starts with
    //initialize cards;
    temp3.face, temp4.face ="";
    temp3.suit, temp4.suit ="";
    
    calcStats(val, bust, blckJ, stand);
    
    cout<<"Would you like to bet in this game: (y or n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')
            bet = true;
    
    do{
        cout<<"Would you like to see the odds for this game: (y or n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')
            pStats(bust, blckJ, stand);
        if(bet == true){
            if(pMoney < 2){
                cout<<"You do not have enough money to bet"<<endl;
                cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)"; //show list of players plays
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                break;
            }
            cout<<"You have $"<<pMoney<<endl;
            bool accept = false;
            do{
                cout<<"How much would you like to bet: Minimum bet is $2";
                cin>>bMoney;
                if(bMoney >= 2)
                    accept = true;
            }while(!accept);
        }
            
        temp3.face, temp4.face="";
        
        //player cards
        if(deck.empty())//check deck
            deck = setDeck();
        temp1 = deck.front();
        pMove.push(temp1);  //add card to player moves
        deck.pop();
        if(deck.empty())//check deck
            deck = setDeck();
        temp2 = deck.front(); 
        pMove.push(temp2); //add card to player moves
        deck.pop();
        //display player cards
        cout<<"\nYour first two cards are:"<<endl;
        cout<<temp1.face<<" of "<<temp1.suit<<endl;
        cout<<setw(7)<<"&"<<endl;
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
        else if(temp1.face.compare(temp2.face) == 0 && pMoney > bMoney * 2) { //special case for if cards are the same face
            cout<<"Would you like to split: (y or n)";
            cin>>choice;
            if(choice == 'y' || choice =='Y'){
                play = split(scores, val, deck, pMoney, bMoney, temp1, temp2, pMove, dMove); //call split function return whether player still plays
                if(play == true)
                    continue;
                else{//if not playing exit game and display scores
                    if(bet)
                        cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                    cout<<"Would you like to see your plays: (y or n)"; //show list of players plays
                    cin>>choice;
                    if(choice == 'y' || choice == 'Y')
                        showPlays(scores);
                    cout<<"Would you like to see game stats: (y or n)";
                    cin>>choice;
                    if(choice == 'y' || choice == 'Y')
                        stats(pMove, dMove);
                    play = false;
                    break;
                }
            }
            else
                pTotal = val[temp1.face]+val[temp2.face];
        }
        else
            pTotal = val[temp1.face] + val[temp2.face];
        cout<<"Player:"<<pTotal<<endl;
        
        if(pTotal == 21){//check for win
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney += bMoney * 1.5;
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//if not exit game and display scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)"; //show list of players plays
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        else if(pTotal > 21){//check if player lose
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney -= bMoney;
            cout<<"\nBUST"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//if not exit game and display scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        
        //dealer cards
        if(deck.empty())//check deck
            deck = setDeck();
        temp1 = deck.front();
        dMove.push(temp1);  //add card to dealer moves
        deck.pop();
        if(deck.empty())//check deck
            deck = setDeck();
        temp2 = deck.front(); 
        dMove.push(temp2);  //add card to dealer moves
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
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney -= bMoney;
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"The dealer won"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game and show scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        else if(dTotal > 21){//check if dealer loose
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney += bMoney;
            cout<<"\nThe dealer bust"<<endl;
            cout<<"YOU WIN"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game and show scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        
        do{//hit player with more  cards until they bust, win, or do not want more
            //Player can double down if they have 9, 10, or 11
            if(pTotal == 9 || pTotal == 10 || pTotal == 11){
                if(bet){
                    cout<<"Would you like to double down: (y or n)";
                    cin>>choice;
                    if(choice == 'y' || choice == 'Y' && bMoney * 2 < pMoney){
                        bMoney *= 2;
                        if(deck.empty())//check deck
                        deck = setDeck();
                        temp1 = deck.front();
                        pMove.push(temp1);  //add card to player moves
                        deck.pop();
                        //display card
                        cout<<"\nNext card is"<<endl;
                        cout<<temp1.face<<" of "<<temp1.suit<<endl;
                        pTotal += val[temp1.face];
                        cout<<"Player:"<<pTotal<<endl;
                        break;
                    }
                    if(pMoney < bMoney * 2){
                        cout<<"You do not have enough money to double down"<<endl;
                    }
                }
            }
            
            cout<<"\nWould you like to hit? (y or n)";
            cin>>choice;
            if(choice == 'y'){//check if player hit
                if(deck.empty())//check deck
                    deck = setDeck();
                temp1 = deck.front();
                pMove.push(temp1);  //add card to player moves
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
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney += bMoney * 1.5;
            temp3.face="";
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game and display scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        else if(pTotal > 21){//check for bust
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney -= bMoney;
            temp3.face="";
            cout<<"\nBUST"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game and display scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        else if(pTotal < 21){//dealer's turn
            while(dTotal < 18){//if 18 dealer automatically stops hitting
                if(deck.empty())//check deck
                    deck = setDeck();
                temp1 = deck.front();
                dMove.push(temp1);  //add card to dealer moves
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
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney -= bMoney;
            temp4.face="";
            cout<<"\nBLACKJACK!!"<<endl;
            cout<<"The dealer won"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game and display scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        else if(dTotal > 21){//check dealer bust
            scores.push_front(pTotal);  //add player score to list
            if(bet)
                pMoney += bMoney;
            temp4.face="";
            cout<<"\nThe dealer bust"<<endl;
            cout<<"YOU WON"<<endl;
            cout<<"Would you still like to play? (y or n)";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){//check if player still plays
                play = true;
                continue;
            }
            else{//exit game and display scores
                if(bet)
                    cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
                cout<<"Would you like to see your plays: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
                cout<<"Would you like to see game stats: (y or n)";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
                play = false;
                break;
            }
        }
        scores.push_front(pTotal);  //add player score to list
        if(dTotal < 21 && pTotal < 21){//determine winner
            if(dTotal == pTotal)//if neither win
                cout<<"\nDraw"<<endl;
            else if(dTotal > pTotal){//dealer winner if higher
                cout<<"\nThe dealer won this hand"<<endl;
                if(bet)
                    pMoney -= bMoney;
            }
            else{//player winner if lower
                cout<<"\nYou won this hand"<<endl;
                if(bet)
                    pMoney += bMoney;
            }
        }
        temp3.face,temp4.face="";
        
        cout<<"Would you still like to play? (y or n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')//check if player still plays
            play = true;
        else{//exit game and display scores
            if(bet)
                cout<<"You have $"<<pMoney<<endl; //show player's total amount of money
            cout<<"Would you like to see your plays: (y or n)";
            cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    showPlays(scores);
            cout<<"Would you like to see game stats: (y or n)";
            cin>>choice;
                if(choice == 'y' || choice == 'Y')
                    stats(pMove, dMove);
            play = false;
        }
    }while(play);    
}
//add suits to card structure
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
//randomly add cards to deck
queue<card> setDeck(){
    //display output
    //cout<<"Shuffling the cards"<<endl;
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
//map faces to actual values
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

//set of cards randomized
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
//show user plays and blackjacks
void showPlays(list<int> scores){
    list<int>::iterator itr;
    int bJack = 0;
    int i = 0;
    cout<<"Displaying scores from first game to last"<<endl;
    for(itr = scores.begin(); itr != scores.end(); itr++ ){
        i++;
        cout<<"Game "<<i<<" "<<*itr<<endl;
    }
    scores.sort();
    for(itr = scores.begin(); *itr <= 21; itr++){
        if(*itr!= 21)
            continue;
        bJack++;
    }
    cout<<"You got "<<bJack<<" blackJacks"<<endl;    
}
//game of split cards
bool split(list<int>& sc, map<string, int> val, queue<card> &deck, int &pm, int bm, card t1, card t2, stack<card>&pMove, stack<card>&dMove){
    card temp;
    char choice;
    bool play, hit;
    int pT1, pT2, dTotal;
    
    hit = true;
    
    //Play with the first card
    cout<<"First card"<<endl;
    cout<<t1.face<<" of "<<t1.suit<<endl;
    pT1 = val[t1.face];
    do{
        if(deck.empty())//check deck
           deck = setDeck();
        temp = deck.front();
        pMove.push(temp);  //add card to player moves
        deck.pop();
        cout<<"Your next card is\n"<<temp.face<<" of "<<temp.suit<<endl;
        pT1 += val[temp.face];
        if(pT1 == 21){
            cout<<"BLACKJACK!!!"<<endl;
            pm += bm + 1.5;
            hit = false;
        }
        else if(pT1 > 21){
            cout<<"You bust"<<endl;
            pm -= bm;
            hit = false;
        }
        else
        cout<<"Would you like to hit: (y or n)"<<endl;
        cin>>choice;
        if(choice != 'y' || choice != 'Y')
            hit=false;
    }while(!hit);
    
    hit = true; //reset hit
    //play with second card
    cout<<"Second card"<<endl;
    cout<<t2.face<<" of "<<t2.suit<<endl;
    pT2 = val[t2.face];
    do{
        if(deck.empty())//check deck
           deck = setDeck();
        temp = deck.front();
        pMove.push(temp);  //add card to player moves
        deck.pop();
        cout<<"Your next card is\n"<<temp.face<<" of "<<temp.suit<<endl;
        pT2 += val[temp.face];
        if(pT2 == 21){
            cout<<"BLACKJACK!!!"<<endl;
            pm += bm + 1.5;
            hit = false;
        }
        else if(pT2 > 21){
            cout<<"You bust"<<endl;
            pm -= bm;
            hit = false;
        }
        else
        cout<<"Would you like to hit: (y or n)"<<endl;
        cin>>choice;
        if(choice != 'y' || choice != 'Y')
            hit=false;
    }while(!hit);
    
    if(pT1 >= 21 && pT2 >= 21){
        cout<<"Would you still like to play? (y or n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')//check if player still plays
            return true;
        else//exit game and display scores
            return false;
    }
    else{
        cout<<"Dealer's hand"<<endl;
        if(deck.empty())//check deck
           deck = setDeck();
        temp = deck.front();
        dMove.push(temp);  //add card to player moves
        deck.pop();
        dTotal = val[temp.face];
        cout<<temp.face<<" of "<<temp.suit<<endl;
        cout<<setw(8)<<"&"<<endl;
        if(deck.empty())//check deck
           deck = setDeck();
        temp = deck.front();
        dMove.push(temp);  //add card to player moves
        deck.pop();
        dTotal += val[temp.face];
        cout<<temp.face<<" of "<<temp.suit<<endl;
        do{
            if(deck.empty())//check deck
                deck = setDeck();
            temp = deck.front();
            dMove.push(temp);  //add card to player moves
            deck.pop();
            dTotal += val[temp.face];
            cout<<temp.face<<" of "<<temp.suit<<endl;
        }while(dTotal < 18);
        
        if(dTotal == 21 && pT1 < 21)
            pm -= bm;
        if(dTotal == 21 && pT2 < 21)
            pm -= bm;
        if(dTotal > 21 && pT1 < 21)
            pm += bm;
        if(dTotal > 21 && pT2 < 21)
            pm += bm;
        if(dTotal < 21){
            if(dTotal > pT1)
                pm -= bm;
            if(dTotal > pT2)
                pm -= bm;
            if(dTotal < pT1)
                pm += bm;
            if(dTotal < pT2)
                pm += bm;
        }
        cout<<"Would you still like to play? (y or n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')//check if player still plays
            return true;
        else//exit game and display scores
            return false;  
    }
}
//list all cards dealt in game
void stats(stack<card> player, stack<card> dealer){
    int pSize, dSize;
    stack<card> temp;
    card display;
    pSize = player.size();
    dSize = dealer.size();
    int j = 0; 
    card *pTemp = new card[pSize];
    card *dTemp = new card[dSize];
    card *sort = new card[pSize];
    temp = player;
    for(int i = 0; i < pSize; i++){
        pTemp[i] = temp.top();
        temp.pop();
    }
    temp = dealer;
    for(int i = 0; i < dSize; i++){
        dTemp[i] = temp.top();
        temp.pop();
    }
    
    //sort list of cards
    cout<<"here"<<endl;
    mrgSort(pTemp, sort, 0, pSize);
    sort = new card[dSize];
    mrgSort(dTemp, sort, 0, dSize);
    //list all cards dealt to player
    cout<<"\nList of player cards"<<endl;
    for(int i = 0; i < pSize; i++)
        cout<<pTemp[i].face<<" of "<<pTemp[i].suit<<endl;
    //list all cards dealt to dealer
    cout<<"\nList of dealer cards"<<endl;
    for(int i = 0; i < dSize; i++)
        cout<<dTemp[i].face<<" of "<<dTemp[i].suit<<endl;
}

void pStats(float bust, float blckJ, float stand){
    cout<<"Odds of hands for this game"<<endl;
    cout<<"Odds of BlackJack               : "<<blckJ<<endl;
    cout<<"Odds of Bust                    : "<<bust<<endl;
    cout<<"Odds of hands between 18 and 21 : "<<stand<<endl;
}

//calculate stats
void calcStats(map<string, int> val, float &bust, float &blckJ, float &stand){
    bust = 0;
    blckJ = 0;
    stand = 0;
    int hand;
    int count = 10000;
    int total = 21;
    queue<card> deck = setDeck();
   
    for(int i = 0; i < count; i++){
        hand = recuStats(total, deck, val);
        if(hand == 0)
            blckJ++;
        else if(hand < 0)
            bust++;
        else
            stand++;
    }
    
    blckJ /= count;
    bust /= count;
    stand /= count;
}
//recursively create a hand
int recuStats(int total, queue<card> &deck, map<string, int> val){
    card temp;
    if(total <= 3)
        return total;
    else{
        if(deck.empty())//check deck
            deck = setDeck();
        temp = deck.front();
        deck.pop();
        return recuStats(total - val[temp.face], deck, val);
    }  
} 

void mrgSort(card *a, card *temp, int beg,int end){
    int center=(beg+end)/2;//Split the task down the middle
    if((center-beg)>1)mrgSort(a,temp,beg,center);//Got to be an array to split
    if((end-center)>1)mrgSort(a,temp,center,end);//Got to be an array to split
    merge(a, temp, beg,center,end);//Merge the sorted arrays into 1 larger sorted array
}

void merge(card *a, card *temp, int beg,int nlow,int nhigh){
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
    value["jack"] = 11;
    value["queen"] = 12;
    value["king"] = 13;
    
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge the split
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){//Low done fill with the higher end of array
            temp[i]=a[cnth++];
        }else if(cnth==nhigh){//High done fill with lower end of array
            temp[i]=a[cntl++];
        }else if(value[a[cntl].face]<value[a[cnth].face]){
            temp[i]=a[cntl++];//Fill with lower end
        }else{
            temp[i]=a[cnth++];//Fill with higher end
        }
    }
    //Copy back from the working array to the sorted array
    for(int i=0;i<span;i++){
        a[beg+i]=temp[i];
    }
}

void displayRule(){//Display the rules of the game
    cout<<setw(10)<<"BlackJack Rules"<<endl;
    cout<<"1. Your goal is to get as close to 21 without going over\n"
          "2. If you get 21 exactly that is considered BlackJack and\n"
          "an automatic win\n"
          "3. If you go over 21 that is considered a bust and an\n"
          "automatic loss\n"
          "4. If you are under 21 then you play against dealer if\n"
          "dealer has 21 or cards higher than you, you lose, if your\n"
          "cards are higher then dealers you win\n"
          "5. If your first two cards are the same face, you may split\n"
          "and play two hands"<<endl;
    cout<<"\nBetting"<<endl;
    cout<<"1. You have the option to play with bets, if you chose to\n"
          "play with bets the game is over once you have no more money\n"
          "or you choose to quit\n"
          "2. There is a minimum bet of $2\n"
          "3. If you get BlackJack you receive 1.5 times your bet back\n"
          "4. If you beat the dealer you receive your 1 times your bet back\n"
          "5. If you lose you lose your bet\n"
          "6. If your first 2 cards equal 9, 10, or 11 you have the option to\n"
          "7. double down, this doubles your bet and you receive only one more\n"
          "card to beat the dealer\n"
          "8. If your first 2 cards share the same face, you can only split\n"
          "if you have enough to double your bet, same goes with doubling down"<<endl;      
}
