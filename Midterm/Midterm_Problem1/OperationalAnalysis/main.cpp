/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Edited By: Janaye Jackson
 * Purpose:  Operational Analysis binary and linear search
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Library
#include <ctime>      //Time Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow
int Obb,Oib,Ojb, Obl, Oil, Ojl;

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
    int perLine=10;
    int bTotal, lTotal;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    bublSrt(array,SIZE);
    selSort(brray,SIZE);
    
    //Test the linear search by randomly choosing a value and
    //determine if found;
    int value=rand()%(highRng-lowRng+1)+lowRng;
    //int value = -1;
    cout<<"Using the Linear Search"<<endl;
    cout<<"The value "<<value<<" was found at position "
            <<linSrch(array,SIZE,value)<<endl;
    cout<<"Using the Binary Search"<<endl;
    cout<<"The value "<<value<<" was found at position "
            <<binSrch(brray,SIZE,value)<<endl;
    
    bTotal = Obb + Oib + Ojb;
    lTotal = Obl + Oil + Ojl;
    cout<<"Binary Search Operational Analysis"<<endl;
    cout<<"N     = "<<SIZE<<endl;
    cout<<"Ob    = "<<Obb<<endl;
    cout<<"Oi    = "<<Oib<<endl;
    cout<<"Oj    = "<<Ojb<<endl;
    cout<<"Total = "<<bTotal<<endl;
    cout<<"\nLinear Search Operational Analysis"<<endl;
    cout<<"N     = "<<SIZE<<endl;
    cout<<"Ob    = "<<Obl<<endl;
    cout<<"Oi    = "<<Oil<<endl;
    cout<<"Oj    = "<<Ojl<<endl;
    cout<<"Total = "<<lTotal<<endl;
    
    if(lTotal < bTotal)
        cout<<"Linear search has a shorter operational analysis"<<endl;
    else
        cout<<"Binary search has a shorter operational analysis"<<endl;

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
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
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
    do{
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
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
    Obb+=4;
    //Loop until value found not indexes
    do{
        Oib +=4;
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle]){
            Ojb+=1;
            return middle;}
        else if(val>a[middle]){
            Ojb+=4;
            lowEnd=middle+1;
        }
        else{
            Ojb+=4;
            highEnd=middle-1;
        }
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val){
    Obl+=4;
    for(int indx=0;indx<n;indx++){
        Oil+=4;
        if(val==a[indx]){
            Ojl+=1;
            return indx;
        }
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

