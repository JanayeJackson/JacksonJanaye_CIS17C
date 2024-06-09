/* 
 * File:   SimpleVectorPush.h
 * Author: Dr. Mark E. Lehr
 * Purpose:  Simple Vector only works with Class Wrapper Objects
 *           Inefficient Push implemented
 */

#ifndef SIMPLEVECTORLIST_H
#define	SIMPLEVECTORLIST_H

// SimpleVector class template
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

#include "LinkedList.h"

template <class T>
class SimpleVectorList{
    private:
       LinkedList<T> *aptr;  //Pointer to Linked List
       void memError();      // Handles memory allocation errors
       void subError();      // Handles subscripts out of range

    public:
       // Constructor declaration
       SimpleVectorList(const T &);

       // Copy constructor declaration
       SimpleVectorList(const SimpleVectorList &);

       // Destructor declaration
       ~SimpleVectorList();

       // Access to return the array size
       int size() const
          { return aptr->cntLst(); }

       // Access to return a specific element
       T getElementAt(int position);

       // Overloaded [] operator declaration
       T &operator[](const int &);
       
       void push(const T &);
       // Number of operations run 
       int Ob = 0;
       int Oi = 0;
       int Oj = 0;
       int Os = 0;     
};

//***********************************************************
// Push the new value by allocating, copying, then adding
// new value
//***********************************************************

template <class T>
void SimpleVectorList<T>::push(const T &val){
    //Add a value into the Linked List
    Ob+=1;
    aptr->addLst(val);
    Oi = aptr->oi;
    Oj = aptr->oj;
    Os = 0;
}

//***********************************************************
// Constructor for SimpleVector class with 1 object
//***********************************************************

template <class T>
SimpleVectorList<T>::SimpleVectorList(const T &d){
    aptr=new LinkedList<T>(d); 
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVectorList<T>::SimpleVectorList(const SimpleVectorList &obj){
   // Allocate memory for the array.
   aptr = new LinkedList<T>(obj.aptr->getObj(0));
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 1; count < obj.size(); count++){
       aptr->addLst(obj.aptr->getObj(count));
   }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVectorList<T>::~SimpleVectorList(){
      delete aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVectorList<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVectorList<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// script in the array.                                  *
//*******************************************************

template <class T>
T SimpleVectorList<T>::getElementAt(int sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getObj(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVectorList<T>::operator[](const int &sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getPtr(sub);
}

#endif	/* SIMPLEVECTORList_H */

