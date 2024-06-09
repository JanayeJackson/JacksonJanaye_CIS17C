
/* 
 * File:   main.cpp
 * Author: Janaye Jackson
 *
 * Created on April 11, 2024, 6:19 PM
 */

//System Level Libraries

#include <iostream>  //Input-Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units

//Function Prototypes
//replacement permutation
unsigned long int rPerm(int, int);
//no replacement permutation
unsigned long int perm(int, int);
//replacement combination
unsigned long int rCom(int, int);
//no replacement combination
unsigned long int com(int, int);
//factorial with recursion
unsigned long int fact(int, int);

//Execution begins here!
int main(int argc, char** argv) {
    //Initialize Random Seed once here!
    
    //Declare Variables
    int n, m;
    
    //Initialize Variables
    
    //Map the inputs/known to the outputs
    //headers
    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    
    //input
    do{
        cout<<"N -> Number of total elements"<<endl;
        cin>>n;
    }while(n<2 || n>26);
    
    do{
        cout<<"M -> Number of elements to take from the total"<<endl;
        cin>>m;
    }while(m<=0 || m>=n);
    cout<<" N  M   P Rep   P no Rep         C Rep           C no Rep"<<endl;
    cout<<"         N^M    N!/(N-M)!  (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl;
    cout<<setw(2)<<n<<setw(3)<<m;
    cout<<setw(8)<<rPerm(n,m)<<setw(11)<<perm(n,m)<<setw(21)<<rCom(n,m)<<setw(14)<<com(n,m)<<endl;
    
    //Display the outputs
    
    //Exit the program

    return 0;
}

unsigned long int rPerm(int n, int m){
    int p = 1;
    for(int i =1; i<=m; i++){
        p *=n;
    }
    return p;
}

unsigned long int perm(int n, int m){
    long int p = fact(n, n-m);
    return p;
    
}
unsigned long int rCom(int n, int m){
    unsigned long int c = fact(n+m-1, n-1);
    c /= fact(m, 1);
    return c;
}

unsigned long int com(int n, int m){
    unsigned long int c = fact(n, m);
    c /= fact(n-m, 1);
    return c;
}

unsigned long int fact(int n, int r){
    if(n==r+1)
        return r+1;
    else{
        return n * fact(n-1, r);
    }
}