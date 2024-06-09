/*
 * Author: Janaye Jackson
 * Created May 15th, 20234
 * shell sort algorithm 
 * https://www.geeksforgeeks.org/shellsort/
 * Description: Timing analysis of shell Sort
 */
#include <iostream>
using namespace std;


//Global Constants

//Function Prototypes
void fillAry(int *, int);
int shellSort(int *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the arrays
    const int SIZE=100000000;
    //Fill aray 
    int *arr = new int[SIZE];
    fillAry(arr, SIZE);
    //Sort the arrays then print
    int beg=time(0);
    shellSort(arr, SIZE);
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


