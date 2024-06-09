

/* 
 * File:   main.cpp
 * Author: Nicolai M. Josuttis, Addison-Wesley
 *
 * Created on April 9, 2024, 7:38 PM
 */

#include <iostream>
#include <string>
#include "Queue.hpp"      // use special queue class
using namespace std;

int main()
{
   try {    
      Queue<string> q;

      // insert three elements into the queue
      q.push("These ");
      q.push("are ");
      q.push("more than ");

      // read and print two elements from the queue
      cout << q.pop();
      cout << q.pop();

      // push two new elements
      q.push("four ");
      q.push("words!");

      // skip one element
      q.pop();

      // read and print two elements from the queue
      cout << q.pop();
      cout << q.pop() << endl;

      // print number of remaining elements
      cout << "number of elements in the queue: " << q.size()
           << endl;

      // read and print one element
      cout << q.pop() << endl;
   }
   catch (const exception& e) {
      cerr << "EXCEPTION: " << e.what() << endl;
   }
}