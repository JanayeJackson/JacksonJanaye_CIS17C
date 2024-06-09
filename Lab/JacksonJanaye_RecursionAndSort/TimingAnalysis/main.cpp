/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on May 15, 2024
 * Timing Analysis of different sort methods
 */
#include <cstdlib>
#include <iostream>
using namespace std;
//Global Constants

//Function Prototypes
void fillAry(int *, int);
void heapify(int *, int, int);
void heapsort(int *, int);
int partition(int *, int, int);
void quickSort(int *, int, int);
int shellSort(int *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));

    const int SIZE=10000000;
    //Allocate and fill arrays 
    int *arr = new int[SIZE];
    fillAry(arr, SIZE);
    int *qArr, *hArr;
    qArr = arr;
    hArr = arr;
    //Sort the arrays record time
    //shell sort
    int beg=time(0);
    shellSort(arr, SIZE);
    int sTime=time(0)-beg;
    //q sort
    beg=time(0);
    quickSort(qArr,0, SIZE -1);
    int qTime=time(0)-beg;
    //heap sort
    beg=time(0);
    heapsort(hArr, SIZE);
    int hTime=time(0)-beg;
    
    cout<<"Timing Analysis of Different Sorting Algorithms - size N = "<<SIZE<<endl;
    cout<<"Total Run Time shellSort = "<<sTime<<" seconds"<<endl;
    cout<<"Total Run Time quickSort = "<<qTime<<" seconds"<<endl;
    cout<<"Total Run Time heapSort = "<<hTime<<" Seconds"<<endl;
    //De-allocate data
    delete arr;
    delete qArr;
    delete hArr;
    //Exit stage right
    return 0;
}

void fillAry(int *arr, int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand();
    }
}
 
void heapify(int *arr, int n, int i) { 
    int temp, maximum, left_index, right_index; 
    // currently assuming i postion to be holding the largest value 
    maximum = i; 
    // right child index 
    right_index = 2 * i + 2; 
    // left child index 
    left_index = 2 * i + 1; 
    // if left index value is grater than the current index value 
    if (left_index < n && arr[left_index] > arr[maximum]) 
        maximum = left_index; 
    // if right index value is grater than the current index value 
    if (right_index < n && arr[right_index] > arr[maximum]) 
        maximum = right_index; 
    // checking if we needed swaping the elements or not 
    if (maximum != i) { 
        temp = arr[i]; 
        arr[i] = arr[maximum]; 
        arr[maximum] = temp; 
        heapify(arr, n, maximum); 
    } 
} 
  
// HeapSorting function 
void heapsort(int *arr, int n) { 
    int i, temp; 
    // performing heapify on the non leaf nodes so n/2 - 1 to 0 are the non leaf nodes 
    for (i = n / 2 - 1; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
    // the current array is changed to max heap 
    for (i = n - 1; i > 0; i--) { 
        temp = arr[0]; 
        arr[0] = arr[i]; 
        arr[i] = temp; 
        heapify(arr, i, 0); 
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

/* function to sort arr using shellSort */
int shellSort(int *arr, int n){
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}




