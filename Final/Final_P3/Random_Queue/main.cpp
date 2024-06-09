/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on June 4, 2024, 7:54 PM
 */

#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;

int random(int);


int main(int argc, char** argv) {
     //Initialize Random Seed once here!
    srand(static_cast<unsigned int>(time(0)));
    queue<int> cstmr;
    vector<int> clerk;
    clerk.push_back(random(60));
    clerk.push_back(random(80));
    clerk.push_back(random(120));
    int arrival = random(15);
    int add = 4;
    int service = 1 + 0.75 + 0.5;
    int time = 60 * 60 * 24;
    int amntC = 4;
    int temp = 0, max = 4;
    for(int i = 0; i < add; i++)
        cstmr.push(1);
    
    for(int i = 0; i < time; i+=1){
        temp = cstmr.size();
        if(temp > max)
            max = temp;
        if(cstmr.empty() && clerk.size() != 3)
            clerk.pop_back();
        if(i % arrival == 0){
            arrival = random(15);
            cstmr.push(1);
            amntC++;
            if(cstmr.size() > (clerk.size() - 2)*5)
                clerk.push_back(60);
        }
        if(i % clerk[0] == 0){
            if(cstmr.empty()){
                continue;
            }
            for(int k = 0; k < clerk.size()-2; k++)
                cstmr.pop();
        }
        if(i % clerk[1] == 0){
            if(cstmr.empty())
                continue;
            cstmr.pop();
        }
        if(i % clerk[2] == 0){
            if(cstmr.empty())
                continue;
            cstmr.pop();
        }
        
        
    }
    float wait = float(time)/amntC;
    cout<<"In "<<time<<" seconds "<<amntC<<" customers were processed "<<endl;
    cout<<"Average wait:"<<wait<<endl;
    cout<<"Max customers:"<<max<<endl;

    return 0;
    }

int random(int num){
    int min, max;
    min = num - int(num*0.5);
    max = num + int(num*0.5);
    return min + rand()%(max - min);
}

