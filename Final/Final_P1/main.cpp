// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Hash{
    int BUCKET;    // No. of buckets
    // Pointer to an array containing buckets
    list<string> *table;
    map<char, int> digit;
public:
    Hash(int V);  // Constructor
    //hash function to search for key
    bool searchItem(string, int&, int&);
    // hash function to map values to key
    int hashFunction(string);
    // inserts a key into hash table
    void insertItem(string);
    // deletes a key from hash table
    void deleteItem(string);
    void displayHash(int&, int&, int&, int&, int&, int&);
};
 
Hash::Hash(int b){
    this->BUCKET = b;
    table = new list<string>[BUCKET];
    digit['A'] = 2;
    digit['B'] = 2;
    digit['C'] = 2;
    digit['D'] = 3;
    digit['E'] = 3;
    digit['F'] = 3;
    digit['G'] = 4;
    digit['H'] = 4;
    digit['I'] = 4;
    digit['J'] = 5;
    digit['K'] = 5;
    digit['L'] = 5;
    digit['M'] = 6;
    digit['N'] = 6;
    digit['O'] = 6;
    digit['P'] = 7;
    digit['Q'] = 7;
    digit['R'] = 7;
    digit['S'] = 7;
    digit['T'] = 8;
    digit['U'] = 8;
    digit['V'] = 8;
    digit['W'] = 9;
    digit['X'] = 9;
    digit['Y'] = 9;
    digit['Z'] = 9;
}

int Hash::hashFunction(string x) {
    int dt = digit[x[0]] * 100;
    dt += digit[x[1]] * 10;
    dt += digit[x[2]];
        return (dt % BUCKET);
}
 
void Hash::insertItem(string key){
    int index = hashFunction(key);
    table[index].push_back(key); 
}
 

void Hash::deleteItem(string key){
  // get the hash index of key
  int index = hashFunction(key);
  // find the key in (index)th list
  list <string> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if ((*i).compare(key) == 0)
      break;
  }
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}

bool Hash::searchItem(string key, int &index, int &count){
    // get the hash index of key
    index = hashFunction(key);
    // search the key in (index)th list
    list <string> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        count++;
        if ((*i).compare(key) == 0)
            return true;
    }
    return false;
}
 
// function to display hash table
void Hash::displayHash(int &nEl, int &oEl, int &tEl, int&thEl, int&fUpEl, int &max) {
    max = 0;nEl = 0;oEl = 0;tEl = 0;thEl = 0;fUpEl = 0;
    int count;
    for (int i = 0; i < BUCKET; i++) {
        count = 0;
        cout << i;
        for (auto x : table[i]){
            cout << " --> " << x;
            count++;
        }
        cout << endl;
        if(count > max)
            max = count;
        switch(count){
            case 0:
                nEl++;break;
            case 1:
                oEl++;break;
            case 2:
                tEl++;break;
            case 3:
                thEl++;break;
            default:
                fUpEl++;break;
        }
  }
}
 
// Driver program 
int main(int argc, char** argv){
    srand(static_cast<unsigned int>(time(0)));
    
    string f = "";
    int size = 512;
    int index, count = 0;
    bool found;
    int max, nEl, oEl, tEl, thEl, fUpEl;
    int coll;
    Hash h(size); //Count of buckets in hash table
    // insert the keys into the hash table
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 3; j++){     
            int t = rand()%26+65;
            f += static_cast<char>(t);
        }
         h.insertItem(f);  
        f = "";
    }
    for(int j = 0; j < 3; j++){     
            int t = rand()%26+65;
            f += static_cast<char>(t);
    }
    //h.insertItem(f);
    found = h.searchItem(f, index, count);
        
    // display the Hash table
    h.displayHash(nEl, oEl, tEl, thEl, fUpEl, max);
    coll = tEl + thEl + fUpEl;
    if(found)
        cout<<f<<"was found in the has table at location "<<index<<" after "<<count<<" nodes"<<endl;
    else
        cout<<f<<" was not found in the hash table after "<<count<<" nodes"<<endl;
    cout<<nEl<<" had no elements"<<endl;
    cout<<oEl<<" had one element"<<endl;
    cout<<tEl<<" had two elements"<<endl;
    cout<<thEl<<" had three elements"<<endl;
    cout<<fUpEl<<" had four or more elements"<<endl;
    cout<<"The max number of elements was "<<max<<endl;
    cout<<"There was a total of "<<coll<<" collisions"<<endl;
    return 0;
}


