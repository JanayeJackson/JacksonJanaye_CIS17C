/*
 * Author: Janaye Jackson
 * Created May 15th, 20234
 * qSort algorithm 
 * https://www.geeksforgeeks.org/cpp-program-for-quicksort/
 * Description: Timing analysis of qSort
 */
#include <iostream>
using namespace std;


//Global Constants

//Function Prototypes
void fillAry(int *, int);
int partition(int *, int, int);
void quickSort(int *, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the arrays
    const int SIZE=10000000;
    //Fill aray 
    int *arr = new int[SIZE];
    fillAry(arr, SIZE);
    //Sort the arrays then print
    int beg=time(0);
    quickSort(arr, 0, SIZE - 1);
    int totTime=time(0)-beg;
    cout<<"Total Run Time = "<<totTime<<" Seconds"<<endl;
    //De-allocate data
    delete arr;
    //Exit stage right
    return 0;
}

void fillAry(int *arr, int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand();
    }
}

int partition(int *arr, int start, int end){
    int pivot = arr[start];
    int count = 0;
    
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) 
            i++;
        while (arr[j] > pivot) 
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}
 
void quickSort(int *arr, int start, int end){
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}