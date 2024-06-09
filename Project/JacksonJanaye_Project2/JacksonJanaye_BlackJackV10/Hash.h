/* 
 * File:   Hash.h
 * Author: Janaye Jackson
 *
 * Created on June 6, 2024, 11:58 AM
 */

#ifndef HASH_H
#define HASH_H


// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "card.h"
using namespace std;

class Hash{
    int BUCKET;    // No. of buckets
    // Pointer to an array containing buckets
    list<card> *table;
    map<string, int> faces, suits;
public:
    Hash(int V);  // Constructor
    //hash function to search for key
    bool searchItem(card, int&, int&);
    // hash function to map values to key
    int hashFunction(card);
    // inserts a key into hash table
    void insertItem(card);
    // deletes a key from hash table
    void deleteItem(card);
    void displayHash();
};
 
Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<card>[BUCKET];
    faces["ace"] = 1;
    faces["two"] = 2;
    faces["three"] = 3;
    faces["four"] = 4;
    faces["five"] = 5;
    faces["six"] = 6;
    faces["seven"] = 7;
    faces["eight"] = 8;
    faces["nine"] = 9;
    faces["ten"] = 10;
    faces["jack"] = 11;
    faces["queen"] = 12;
    faces["king"] = 13;
    
    suits["spades"] = 0;
    suits["hearts"] = 13;
    suits["diamonds"] = 26;
    suits["clubs"] = 39;
}

int Hash::hashFunction(card x) {
    int dt = faces[x.face] + suits[x.suit];
        return (dt % BUCKET);
}
 
void Hash::insertItem(card key){
    int index = hashFunction(key);
    table[index].push_back(key); 
}
 

void Hash::deleteItem(card key){
  // get the hash index of key
  int index = hashFunction(key);
  // find the key in (index)th list
  list <card> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if ((*i).face.compare(key.face) == 0)
      break;
  }
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}

bool Hash::searchItem(card key, int &index, int &count){
    // get the hash index of key
    index = hashFunction(key);
    // search the key in (index)th list
    list <card> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        count++;
        if ((*i).face.compare(key.face) == 0)
            return true;
    }
    return false;
}
 
// function to display hash table
void Hash::displayHash() {
    int count, max = 0;
    string face, suit, temp, temp2;
    for (int i = 0; i < BUCKET; i++) {
        count = 0;
        cout << i;
        for (auto x : table[i]){
            temp = x.face;
            temp2 = x.suit;
            count++;
        }
        cout << endl;
        if(count > max){
            max = count;
            face = temp;
            suit = temp2;
        }
  }
}


#endif /* HASH_H */

