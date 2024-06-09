/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Edited By: Janaye Jackson
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
int Obb,Osb, Oib,Ojb, Obs, Ois, Ojs, Oss;

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void bublSrt(int [],int);
void selSort(int [],int);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=100;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=200;
    //int lowRng=100,highRng=SIZE*2;
    int perLine=10;
    int bTotal, sTotal;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    bublSrt(array,SIZE);
    selSort(brray,SIZE);

    bTotal = Obb + Oib + Ojb, Osb;
    sTotal = Obs + Ois + Ojs, Oss;
    cout<<"Bubble Sort Operational Analysis"<<endl;
    cout<<"N     = "<<SIZE<<endl;
    cout<<"Ob    = "<<Obb<<endl;
    cout<<"Oi    = "<<Oib<<endl;
    cout<<"Oj    = "<<Ojb<<endl;
    cout<<"Os    = "<<Osb<<endl;
    cout<<"Total = "<<bTotal<<endl;
    cout<<"\nSelection Sort Operational Analysis"<<endl;
    cout<<"N     = "<<SIZE<<endl;
    cout<<"Ob    = "<<Obs<<endl;
    cout<<"Oi    = "<<Ois<<endl;
    cout<<"Oj    = "<<Ojs<<endl;
    cout<<"Os    = "<<Oss<<endl;
    cout<<"Total = "<<sTotal<<endl;
    
    if(sTotal < bTotal)
        cout<<"Selection Sort has a smaller Operational Analysis"<<endl;
    else
        cout<<"Bubble Sort has a smaller Operational Analysis"<<endl;
    
    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    Obs +=5;
    for(int pos=0;pos<n-1;pos++){
        Oss +=13;
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            Ois += 4;
            if(a[i]<min){
                Ojs+=3;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    Obb +=1;
    do{
        Osb +=5;
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            Oib += 5;
            if(a[i]>a[i+1]){
                Ojb +=8;
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle])return middle;
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val){
    for(int indx=0;indx<n;indx++){
        if(val==a[indx])return indx;
    }
    return -1;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}