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


int main(int argc, char** argv) {
    queue<int> cstmr;
    vector<int> clerk;
    clerk.push_back(60);
    clerk.push_back(80);
    clerk.push_back(120);
    int arrival = 15;
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

