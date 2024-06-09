/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Edited By: Janaye Jackson
 * Created on April 2, 2021, 1:19 PM
 * Purpose: Operational Analysis on Merge and Selection Sort
 *
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Data structure containing an array and a working array
struct Data{
    int size;
    int *sortit;
    int *working;
};

//Global Constants
unsigned long int Obm,Osm, Oim,Ojm, Okm, Obs, Ois, Ojs, Oss;

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
    Obm = 0, Oim = 0, Ojm = 0, Osm = 0, Okm = 0;
    Obs = 0, Ois = 0, Ojs = 0, Oss = 0;
    
    mrgSort(a,0,a->size);
    
    unsigned long int mTotal = Obm + Oim + Ojm + Osm + Okm;
    cout<<"Merge Sort Operational Analysis"<<endl;
    cout<<"N     = "<<SIZE<<endl;
    cout<<"Ob    = "<<Obm<<endl;
    cout<<"Oi    = "<<Oim<<endl;
    cout<<"Oj    = "<<Ojm<<endl;
    cout<<"Ok    = "<<Okm<<endl;
    cout<<"Os    = "<<Osm<<endl;
    cout<<"Total = "<<mTotal<<endl;
  
    selSort(array,SIZE, 5);
    unsigned long int sTotal = Obs + Ois + Ojs + Oss;
    cout<<"\nSelection Sort Operational Analysis"<<endl;
    cout<<"N     = "<<SIZE<<endl;
    cout<<"Ob    = "<<Obs<<endl;
    cout<<"Oi    = "<<Ois<<endl;
    cout<<"Oj    = "<<Ojs<<endl;
    cout<<"Os    = "<<Oss<<endl;
    cout<<"Total = "<<sTotal<<endl;
    Obs = 0, Ois = 0, Ojs = 0, Oss = 0;
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
    Obm += 3;
    int center=(beg+end)/2;//Split the task down the middle
    if((center-beg)>1)mrgSort(a,beg,center);//Got to be an array to split
    if((end-center)>1)mrgSort(a,center,end);//Got to be an array to split
    merge(a,beg,center,end);//Merge the sorted arrays into 1 larger sorted array
}

void merge(Data *a,int beg,int nlow,int nhigh){
    Osm += 9;
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge the split
    //Fill the array
    for(int i=0;i<span;i++){
        Oim+=3;
        if(cntl==nlow){//Low done fill with the higher end of array
            Ojm+=3;
            a->working[i]=a->sortit[cnth++];
        }else if(cnth==nhigh){//High done fill with lower end of array
            Ojm+=4;
            a->working[i]=a->sortit[cntl++];
        }else if(a->sortit[cntl]<a->sortit[cnth]){
            Ojm+=7;
            a->working[i]=a->sortit[cntl++];//Fill with lower end
        }else{
            Ojm+=7;
            a->working[i]=a->sortit[cnth++];//Fill with higher end
        }
    }
    //Copy back from the working array to the sorted array
    for(int i=0;i<span;i++){
        Okm+=4;
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
    Obs +=5;
    for(int pos=0;pos<p;pos++){
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

void copyAry(Data *a, int array[],int n){
    for(int indx=0;indx<n;indx++){
        array[indx]= a->sortit[indx];
    }
}


