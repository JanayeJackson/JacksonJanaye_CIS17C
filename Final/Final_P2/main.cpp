/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

float h(float, stack<float>&);
float g(float, stack<float>&);
void empty(stack<float>&, stack<float>&);

int main(int argc, char** argv) {
    //Testing out recursive trig functions
    stack<float> callH, callG;
    for(float angRad = -1; angRad < 0; angRad+=0.1){
        cout<<"Radian Angle = "<<angRad<<" sinh = "<<sinh(angRad)<<" our h = "<<h(angRad, callH)<<endl;
        cout<<"Radian Angle = "<<angRad<<" cosh = "<<cosh(angRad)<<" our g = "<<g(angRad, callG)<<endl;
        cout<<"Calls for h = "<<callH.size()<<endl;
        cout<<"Calls for g = "<<callG.size()<<endl;
        empty(callH, callG);
    }
    for(float angRad = 0; angRad <= 1; angRad+=0.1){
        cout<<"Radian Angle = "<<angRad<<" sinh = "<<sinh(angRad)<<" our h = "<<h(angRad, callH)<<endl;
        cout<<"Radian Angle = "<<angRad<<" cosh = "<<cosh(angRad)<<" our g = "<<g(angRad, callG)<<endl;
        cout<<"Calls for h = "<<callH.size()<<endl;
        cout<<"Calls for g = "<<callG.size()<<endl;
        empty(callH, callG);
    }
    //Exit stage right
    return 0;
}

void empty(stack<float> &callH, stack<float> &callG){
    while(!callH.empty())
        callH.pop();
    while(!callG.empty())
        callG.pop();
}

float h(float angR, stack<float> &call){
    call.push(angR);
    float tol=1e-6;
    if(angR>-tol&&angR<tol)
        return angR+angR*angR*angR/6;
    return 2*h(angR/2, call)*g(angR/2, call);
}
float g(float angR, stack<float> &call){
    call.push(angR);
    float tol=1e-6;
    if(angR>-tol&&angR<tol)
        return 1+angR*angR/2;
    float b=h(angR/2, call);
    return 1+2*b*b;
}

