/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on May 11, 2024, 1:54 PM
 */

#include <cstdlib>
#include <cmath>
#include<iostream>
#include<iomanip>
using namespace std;

unsigned long long int nlog(unsigned long long int);
unsigned long long int n2log(unsigned long long int);
unsigned long long int nto2(unsigned long long int);
unsigned long long int cfact(unsigned long long int);
unsigned long long int fact(unsigned long long int);
/*
 * 
 */
int main(int argc, char** argv) {
    int n = 1000;
    int min = n * 60;
    int hour = min * 60;
    int day = hour * 24;
    long unsigned int month = day;
    month*=30;
    long long int year = day;
    year *= 365;
    unsigned long long int decade = year * 10;
    unsigned long long int cent = year * 100;
    
    cout<<"Big O()  |Second  |Minute  |Hour      |Day        |Month      |Year       |Decade      |Century      |"<<endl;  
    cout<<"N^(1/3)  |"<<pow(n, 3)<<"   |"<<pow(min, 3)<<"|"<<pow(hour, 3)<<"|"<<pow(day, 3)<<"|"<<
            pow(month, 3)<<"|"<<pow(year, 3)<<"|"<<pow(decade, 3)<<" |"<<pow(cent, 3)<<"  |"<<endl;
    cout<<"N^(1/2)  |"<<pow(n, 2)<<"   |"<<pow(min, 2)<<" |"<<pow(hour, 2)<<" |"<<pow(day, 2)<<"|"<<
            pow(month, 2)<<"|"<<pow(year, 2)<<"|"<<pow(decade, 2)<<" |"<<pow(cent, 2)<<"  |"<<endl;
    cout<<"N        |"<<n<<"    |"<<min<<"   |"<<hour<<"   |"<<day<<"   |"<<
            month<<" |"<<year<<"|"<<decade<<"|"<<cent<<"|"<<endl;
    cout<<"N ln N   |"<<nlog(n)<<"     |"<<nlog(min)<<"|"<<nlog(hour)<<"|"<<nlog(day)<<"|"<<nlog(month)<<"|"
            <<nlog(year)<<"|"<<nlog(decade)<<"|"<<nlog(cent)<<"|"<<endl;
    cout<<"N^2      |"<<fixed<<showpoint<<setprecision(2)<<sqrt(n)<<"   |"<<sqrt(min)<<"|"<<sqrt(hour)<<"|"<<
            sqrt(day)<<"|"<<sqrt(month)<<"|"<<sqrt(year)<<"|"<<sqrt(decade)<<"|"<<sqrt(cent)<<"|"<<endl;
    cout<<"N^2 ln N |"<<n2log(n)<<"      |"<<n2log(min)<<"|"<<n2log(hour)<<"|"<<n2log(day)<<"|"<<n2log(month)<<"|"<<
            n2log(year)<<"|"<<n2log(decade)<<"|"<<n2log(cent)<<"|"<<endl;
    cout<<"2^N      |"<<nto2(n)<<"      |"<<nto2(min)<<"|"<<nto2(hour)<<"|"<<nto2(day)<<"|"<<nto2(month)<<"|"<<
            nto2(year)<<"|"<<nto2(decade)<<"|"<<nto2(cent)<<"|"<<endl;
    cout<<"N!       |"<<cfact(n)<<"       |"<<cfact(min)<<"|"<<cfact(hour)<<"|"<<cfact(day)<<"|"<<cfact(month)<<"|"<<
            cfact(year)<<"|"<<cfact(decade)<<"|"<<cfact(cent)<<"|"<<endl;
   
    return 0;
}

unsigned long long int nlog(unsigned long long int n){
    unsigned long long int temp = 1;
    
    while(temp * log(temp) < n )
        temp++;
    return temp - 1;
}

unsigned long long int n2log(unsigned long long int n){
    unsigned long long int temp = 1;
    
    while(temp * temp * log(temp) < n )
        temp++;
    return temp;
}

unsigned long long int nto2(unsigned long long int n){
    unsigned long long int temp = 1;
    
    while(pow(2, temp) < n)
        temp++;
    return temp;
}

unsigned long long int cfact(unsigned long long int n){
    unsigned long long int temp = 1;
    while(fact(temp) < n)
        temp++;
    return temp -1;
}

unsigned long long int fact(unsigned long long int n){
    
    if(n == 1)
        return 1;
    return n * fact(n - 1);
}