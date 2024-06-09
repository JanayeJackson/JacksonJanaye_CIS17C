/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 2, 2021, 1:19 PM
 * Purpose: Create a Recursive sort
 *
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <ratio>
using namespace std;
using namespace std::chrono;

//Data structure containing an array and a working array
struct Data{
    int size;
    int *sortit;
    int *working;
};

//Global Constants

//Function Prototypes
Data *fill(int);               //Fill the Array
void merge(Data *,int,int,int);//Merge 2 Arrays algorithm
void mrgSort(Data *,int,int);  //Merge Sort Recursions
void destroy(Data *);          //Deallocate
void copyAry(Data *, int [],int);
void selSort(int [],int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Allocate the arrays
    const int SIZE=100000;
    int p = 5;
    Data *a=fill(SIZE);
    int array[SIZE];
    copyAry(a, array, SIZE);
    duration<double, std::milli> totTime;
    high_resolution_clock::time_point t1, t2;
    
    //Sort the arrays and time it
    t1 = high_resolution_clock::now();
    mrgSort(a,0,a->size);
    t2 = high_resolution_clock::now();
    totTime = t2 - t1;
    cout<<"Total Run Time = "<<totTime.count()<<" milliseconds"<<endl;
    
    t1 = high_resolution_clock::now();
    selSort(array,SIZE, p);
    t2 = high_resolution_clock::now();
    totTime = t2 - t1;
    cout<<"Total Run Time = "<<totTime.count()<<" milliseconds"<<endl;
    //De-allocate data
    destroy(a);
    //Exit stage right
    return 0;
}

void destroy(Data *a){
    //Deallocate data elements
    delete []a->sortit;
    delete []a->working;
    delete a;
}

void mrgSort(Data *a,int beg,int end){
    int center=(beg+end)/2;//Split the task down the middle
    if((center-beg)>1)mrgSort(a,beg,center);//Got to be an array to split
    if((end-center)>1)mrgSort(a,center,end);//Got to be an array to split
    merge(a,beg,center,end);//Merge the sorted arrays into 1 larger sorted array
}

void merge(Data *a,int beg,int nlow,int nhigh){
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge the split
    //Fill the array
    for(int i=0;i<span;i++){
        if(cntl==nlow){//Low done fill with the higher end of array
            a->working[i]=a->sortit[cnth++];
        }else if(cnth==nhigh){//High done fill with lower end of array
            a->working[i]=a->sortit[cntl++];
        }else if(a->sortit[cntl]<a->sortit[cnth]){
            a->working[i]=a->sortit[cntl++];//Fill with lower end
        }else{
            a->working[i]=a->sortit[cnth++];//Fill with higher end
        }
    }
    //Copy back from the working array to the sorted array
    for(int i=0;i<span;i++){
        a->sortit[beg+i]=a->working[i];
    }
}

Data *fill(int n){
    //Allocate memory
    Data *data=new Data;
    data->size=n;
    data->sortit=new int[n];
    data->working=new int[n];
    for(int i=0;i<n;i++){
        //data->sortit[i]=mkRndS();
        data->sortit[i]=rand();
    }
    return data;
}

void selSort(int a[],int n, int p){
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<p;pos++){
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

void copyAry(Data *a, int array[],int n){
    for(int indx=0;indx<n;indx++){
        array[indx]= a->sortit[indx];
    }
}


